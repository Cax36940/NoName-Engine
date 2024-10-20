#include "CollidersComponentRegistry.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"
#include "Component/Vector3.hpp"

std::vector<SphereCollider*> CollidersComponentRegistry::registry;
std::vector<CollidersComponentRegistry::Collision> CollidersComponentRegistry::collisions;

void CollidersComponentRegistry::add(SphereCollider* collider)
{
	registry.push_back(collider);
}

void CollidersComponentRegistry::remove(SphereCollider* collider)
{
	for (auto i = registry.begin(); i != registry.end(); i++) {
		if (*i == collider) {
			registry.erase(i);
			break;
		}
	}
}

void CollidersComponentRegistry::check_collisions()
{
	// Check only sphere collisions
	for (auto i = registry.begin(); i != registry.end(); i++) {
		for (auto j = i + 1; j != registry.end(); j++) {
			const Vector3 vector_ji = (*i)->get_position() - (*j)->get_position();
			float minimal_length = (*i)->get_size() + (*j)->get_size();
			if (Vector3::norm2(vector_ji) <= minimal_length * minimal_length) {
				Collision collision = Collision();
				collision.collider1 = *i;
				collision.collider2 = *j;
				collision.collision_distance = minimal_length - Vector3::norm(vector_ji);
				collision.col1_to_col2 = Vector3::normalize(vector_ji);
				collision.normal = collision.col1_to_col2; // Because we are only using Spheres
				collisions.push_back(collision);
			}
		}
	}
}

void CollidersComponentRegistry::solve_collisions()
{
	float coef_elas = 0.9f;

	for each (Collision collision in collisions)
	{
		float m1 = collision.collider1->physical_body->get_mass();
		float m2 = collision.collider2->physical_body->get_mass();
		Vector3 v1 = collision.collider1->physical_body->get_velocity();
		Vector3 v2 = collision.collider2->physical_body->get_velocity();

		float dp1 = m2 / (m1 + m2) * collision.collision_distance;
		float dp2 = m1 / (m1 + m2) * collision.collision_distance;
		collision.collider1->physical_body->set_position(collision.collider1->get_position() + collision.col1_to_col2 * dp1);
		collision.collider2->physical_body->set_position(collision.collider2->get_position() - collision.col1_to_col2 * dp1);

		Vector3 v_relative = v1 - v2;
		float k = ((coef_elas + 1) * Vector3::dot(v_relative, collision.normal)) / (1 / m1 + 1 / m2);
		collision.collider1->physical_body->set_velocity(collision.collider1->physical_body->get_velocity() - k * collision.normal * (1 / m1));
		collision.collider2->physical_body->set_velocity(collision.collider2->physical_body->get_velocity() + k * collision.normal * (1 / m2));
	}

	collisions.clear();
}
