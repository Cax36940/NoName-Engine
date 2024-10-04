#include "PhysicsComponentRegistry.hpp"

void PhysicsComponentRegistry::add(PhysicsComponent* physics_component)
{
	registry.push_back(physics_component);
}

void PhysicsComponentRegistry::remove(PhysicsComponent* physic_component)
{
	for (auto i = registry.begin(); i != registry.end(); i++) {
		if (*i == physic_component) {
			registry.erase(i);
			break;
		}
	}
}

void PhysicsComponentRegistry::registerAllPhysics()
{
	for (PhysicsComponent* physics_component : registry) {
		physics_component->registerPhysics();
	}
}
