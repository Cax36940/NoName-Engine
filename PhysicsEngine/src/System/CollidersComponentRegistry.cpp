#include "CollidersComponentRegistry.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"
#include "Component/Vector3.hpp"

std::vector<SphereCollider*> CollidersComponentRegistry::registry;
std::vector<CollidersComponentRegistry::Collision> CollidersComponentRegistry::collisions;

#define ELASTIC_COEF 0.9

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
			const Vector3 vector_ji = (*i)->physical_body->get_position() - (*j)->physical_body->get_position();
			const float norm2_ij = Vector3::norm2(vector_ji);
			const float minimal_length = (*i)->get_size() + (*j)->get_size();
			if (norm2_ij <= minimal_length * minimal_length) {

				Collision collision1 = Collision();
				Collision collision2 = Collision();
				collision1.particle = (*i)->physical_body;
				collision2.particle = (*j)->physical_body;

				const float norm_ij = std::sqrt(norm2_ij);
				const Vector3 normal = vector_ji * (1/ norm_ij);

				// Compute the distance to separate both objects
				const float collision_distance = minimal_length - norm_ij;

				const float m1 = collision1.particle->get_mass();
				const float m2 = collision2.particle->get_mass();

				collision1.delta_position = ( collision_distance * m2 / (m1 + m2)) * normal;
				collision2.delta_position = (-collision_distance * m1 / (m1 + m2)) * normal;


				// Compute the change in velocity for both objects
				const Vector3 v_relative = collision1.particle->get_velocity() - collision2.particle->get_velocity();
				float k = ((ELASTIC_COEF + 1) * Vector3::dot(v_relative, normal)) / (collision1.particle->get_inv_mass() + collision2.particle->get_inv_mass());
				collision1.delta_velocity = (-k * collision1.particle->get_inv_mass()) * normal;
				collision2.delta_velocity = ( k * collision2.particle->get_inv_mass()) * normal;

				collisions.push_back(collision1);
				collisions.push_back(collision2);
			}
		}
	}
}

void CollidersComponentRegistry::solve_collisions()
{

	for each (Collision collision in collisions)
	{
		collision.particle->set_position(collision.particle->get_position() + collision.delta_position);
		collision.particle->set_velocity(collision.particle->get_velocity() + collision.delta_velocity);
	}

	collisions.clear();
}
