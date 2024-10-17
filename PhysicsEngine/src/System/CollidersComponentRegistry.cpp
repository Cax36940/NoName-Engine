#include "CollidersComponentRegistry.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"
#include "Component/Vector3.hpp"
#include <iostream>

std::vector<SphereCollider*> CollidersComponentRegistry::registry;
std::vector<CollidersComponentRegistry::Collision> CollidersComponentRegistry::collisions;

void CollidersComponentRegistry::add(SphereCollider* collider)
{
	registry.push_back(collider);
	std::cout << "Nb colliders: " << registry.size() << std::endl;
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
			Vector3 d = (*i)->get_position() - (*j)->get_position();
			float minimal_length = (*i)->get_size() + (*j)->get_size();
			if (Vector3::norm2(d) <= minimal_length * minimal_length) {
				Collision collision = Collision();
				collision.collider1 = *i;
				collision.collider2 = *j;
				collision.collision_distance = minimal_length - Vector3::norm(d);
				collision.col1_to_col2 = Vector3::normalize(d);
				collisions.push_back(collision);
				std::cout << "Collision between two particles at " << collision.collider1->get_position().x << std::endl;
			}
		}
	}
}

void CollidersComponentRegistry::solve_collisions()
{
	for each (Collision collision in collisions)
	{
		// dp1 = m2 / (m1 + m2) * d
		float m1 = collision.collider1->physical_body->get_mass();
		float m2 = collision.collider2->physical_body->get_mass();
		float dp1 = m2 / (m1 + m2) * collision.collision_distance;
		Vector3 new_pos = collision.collider1->get_position() + collision.col1_to_col2 * dp1;
		std::cout << collision.collider1->get_position().x << " -> " << new_pos.x << std::endl;
		collision.collider1->physical_body->set_position(new_pos);

		// dp2 = m1 / (m1 + m2) * d
		float dp2 = m1 / (m1 + m2) * collision.collision_distance;
		collision.collider2->physical_body->set_position(
			collision.collider2->get_position() - collision.col1_to_col2 * dp1
		);
	}

	collisions.clear();
}
