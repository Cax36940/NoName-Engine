#include "Component/Physics/PhysicsComponent.hpp"
#include "PhysicsComponentRegistry.hpp"

std::vector<PhysicsComponent*> PhysicsComponentRegistry::registry;

void PhysicsComponentRegistry::add(PhysicsComponent* physics_component)
{
	registry.push_back(physics_component);
}

void PhysicsComponentRegistry::remove(PhysicsComponent* physics_component)
{
	for (auto i = registry.begin(); i != registry.end(); i++) {
		if (*i == physics_component) {
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
