#include "CollisionsRegistry.hpp"

std::vector<CollisionsRegistry::ParticleCollision> CollisionsRegistry::particle_registry;
std::vector<CollisionsRegistry::RigidBodyCollision> CollisionsRegistry::rigidbody_registry;

void CollisionsRegistry::add(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity)
{
	ParticleCollision collision{ particle, delta_position, delta_velocity };
	particle_registry.push_back(collision);
}

void CollisionsRegistry::add(RigidBody* rigidbody, const Vector3& delta_position, const Vector3& impact_point, const Vector3& impact_velocity)
{
	RigidBodyCollision collision{ rigidbody, delta_position, impact_point, impact_velocity };
	rigidbody_registry.push_back(collision);
}

void CollisionsRegistry::remove(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity)
{
	for (auto i = particle_registry.begin(); i != particle_registry.end(); i++) {
		if (i->particle == particle && i->delta_position == delta_position && i->delta_velocity == delta_velocity) {
			particle_registry.erase(i);
			break;
		}
	}
}

void CollisionsRegistry::solve_collisions()
{

	for each (RigidBodyCollision collision in rigidbody_registry)
	{
		collision.rigidbody->add_impact(collision.delta_position, collision.impact_point, collision.impact_velocity);
	}

	for each (ParticleCollision collision in particle_registry)
	{
		collision.particle->set_position(collision.particle->get_position() + collision.delta_position);
		collision.particle->set_velocity(collision.particle->get_velocity() + collision.delta_velocity);
	}

	rigidbody_registry.clear();
	particle_registry.clear();
}
