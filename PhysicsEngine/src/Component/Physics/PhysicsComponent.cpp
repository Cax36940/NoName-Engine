#include "PhysicsComponent.hpp"
#include "../../System/PhysicsComponentRegistry.hpp"

PhysicsComponent::PhysicsComponent()
{
	PhysicsComponentRegistry::add(this);
}

PhysicsComponent::~PhysicsComponent()
{
	PhysicsComponentRegistry::remove(this);
}
