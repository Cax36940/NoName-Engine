#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DefaultSpringForce.hpp"
#include "PhysicsComponent.hpp"

class SimpleSpringComponent : public PhysicsComponent {
	Particle* particle;
	DefaultSpringForce spring_force;

	SimpleSpringComponent(Particle* particle, const float stiffness, const float default_length, const Vector3& fixed_point);

	void changeFixedPoint(const Vector3& new_fixed_point);

	void registerPhysics() override;
};