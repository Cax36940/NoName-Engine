#pragma once
#include "../../Particle.hpp"
#include "PhysicsComponent.hpp"

class DoubleSpringComponent : PhysicsComponent {
	Particle* first;
	Particle* second;
	// SpringForce

	DoubleSpringComponent(Particle* first, Particle* second);

	void RegisterPhysics() override;
};