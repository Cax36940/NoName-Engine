#pragma once
#include "Component/Particle.hpp"
#include "PhysicsComponent.hpp"

class SimpleSpringComponent : public PhysicsComponent {
	Vector3 fixed_point;
	Particle* particle;
	// SpringForce

	SimpleSpringComponent(Vector3 fixed_point, Particle* particle);

	void registerPhysics() override;
};