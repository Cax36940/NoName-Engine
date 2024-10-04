#pragma once
#include "../../Particle.hpp"
#include "PhysicsComponent.hpp"

class SimpleSpringComponent : PhysicsComponent {
	Vector3 fixed_point;
	Particle* particle;
	// SpringForce

	SimpleSpringComponent(Vector3 fixed_point, Particle* particle);

	void registerPhysics() override;
};