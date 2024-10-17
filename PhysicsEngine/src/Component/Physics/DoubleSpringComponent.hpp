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
	DoubleSpringComponent() = default;
	DoubleSpringComponent(const DoubleSpringComponent&) = default;
	DoubleSpringComponent& operator=(const DoubleSpringComponent&) = default;

	DoubleSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& default_length);

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};