#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DefaultSpringForce.hpp"
#include "PhysicsComponent.hpp"

class DoubleSpringComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	DefaultSpringForce first_force;
	DefaultSpringForce second_force;

public:
	DoubleSpringComponent(Particle* first, Particle* second, const float stiffness, const float default_length);

	void registerPhysics() override;
};