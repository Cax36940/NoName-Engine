#include "CollisionsRegistry.hpp"

std::vector<CollisionsRegistry::Collision> CollisionsRegistry::registry;

void CollisionsRegistry::add(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity)
{
	Collision collision{ particle, delta_position, delta_velocity };
	registry.push_back(collision);
}

void CollisionsRegistry::remove(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity)
{
	for (auto i = registry.begin(); i != registry.end(); i++) {
		if (i->particle == particle && i->delta_position == delta_position && i->delta_velocity == delta_velocity) {
			registry.erase(i);
			break;
		}
	}
}

void CollisionsRegistry::solve_collisions()
{

	for each (Collision collision in registry)
	{
		collision.particle->set_position(collision.particle->get_position() + collision.delta_position);
		collision.particle->set_velocity(collision.particle->get_velocity() + collision.delta_velocity);
	}

	registry.clear();
}
