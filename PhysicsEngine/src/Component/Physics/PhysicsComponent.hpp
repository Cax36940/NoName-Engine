#pragma once
#include "System/PhysicsComponentRegistry.hpp"

// Abstract class for Component producing forces
class PhysicsComponent {

public:
	PhysicsComponent() { PhysicsComponentRegistry::add(this); };
	PhysicsComponent(const PhysicsComponent&) { PhysicsComponentRegistry::add(this); };
	~PhysicsComponent() { PhysicsComponentRegistry::remove(this); };

	virtual void registerPhysics() = 0;
};