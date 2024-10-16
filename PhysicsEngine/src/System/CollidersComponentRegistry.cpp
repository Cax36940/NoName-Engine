#include "CollidersComponentRegistry.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"
#include "Component/Vector3.hpp"
#include <iostream>

std::vector<SphereCollider*> CollidersComponentRegistry::registry;

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
			Vector3 d = (*i)->get_position() - (*j)->get_position();
			float minimal_length = (*i)->get_size() + (*j)->get_size();
			if (Vector3::norm2(d) <= minimal_length * minimal_length) {
				std::cout << "Collision between two particles" << std::endl;
			}
		}
	}
}
