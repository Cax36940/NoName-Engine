#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DampedSpringForce.hpp"
#include "PhysicsComponent.hpp"

class DampedDoubleRigidSpringComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	DampedSpringForce first_force;
	DampedSpringForce second_force;

public:
	DampedDoubleRigidSpringComponent() = default;
	DampedDoubleRigidSpringComponent(const DampedDoubleRigidSpringComponent&) = default;
	DampedDoubleRigidSpringComponent& operator=(const DampedDoubleRigidSpringComponent&) = default;

	DampedDoubleRigidSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& damping, const float& default_length);

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};