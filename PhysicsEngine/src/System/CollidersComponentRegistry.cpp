#include "CollidersComponentRegistry.hpp"
#include "CollisionsRegistry.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"
#include "Component/Particle.hpp"
#include "Component/Vector3.hpp"

#define ELASTIC_COEF 0.9

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
			const Vector3 vector_ji = (*i)->physical_body->get_position() - (*j)->physical_body->get_position();
			const float norm2_ij = Vector3::norm2(vector_ji);
			const float minimal_length = (*i)->get_size() + (*j)->get_size();
			if (norm2_ij <= minimal_length * minimal_length) {

				Particle* particle1 = (*i)->physical_body;
				Particle* particle2 = (*j)->physical_body;

				const float norm_ij = std::sqrt(norm2_ij);
				const Vector3 normal = vector_ji * (1/ norm_ij);

				// Compute the distance to separate both objects
				const float collision_distance = minimal_length - norm_ij;

				const float m1 = particle1->get_mass();
				const float m2 = particle2->get_mass();

				const Vector3 delta_position1 = ( collision_distance * m2 / (m1 + m2)) * normal;
				const Vector3 delta_position2 = (-collision_distance * m1 / (m1 + m2)) * normal;


				// Compute the change in velocity for both objects
				const Vector3 v_relative = particle1->get_velocity() - particle2->get_velocity();
				const float k = ((ELASTIC_COEF + 1) * Vector3::dot(v_relative, normal)) / (particle1->get_inv_mass() + particle2->get_inv_mass());
				const Vector3 delta_velocity1 = (-k * particle1->get_inv_mass()) * normal;
				const Vector3 delta_velocity2 = ( k * particle2->get_inv_mass()) * normal;


				CollisionsRegistry::add(particle1, delta_position1, delta_velocity1);
				CollisionsRegistry::add(particle2, delta_position2, delta_velocity2);
			}
		}
	}
}
