#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DefaultSpringForce.hpp"
#include "PhysicsComponent.hpp"

class DoubleRigidSpringComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	DefaultSpringForce first_force;
	DefaultSpringForce second_force;

public:
	DoubleRigidSpringComponent() = default;
	DoubleRigidSpringComponent(const DoubleRigidSpringComponent&) = default;
	DoubleRigidSpringComponent& operator=(const DoubleRigidSpringComponent&) = default;

	DoubleRigidSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& default_length);

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};