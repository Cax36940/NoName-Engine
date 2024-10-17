#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DampedSpringForce.hpp"
#include "PhysicsComponent.hpp"

class DampedDoubleSpringComponent : public PhysicsComponent {
private:	
	Particle* first;
	Particle* second;
	DampedSpringForce first_force;
	DampedSpringForce second_force;

public:
	DampedDoubleSpringComponent() = default;
	DampedDoubleSpringComponent(const DampedDoubleSpringComponent&) = default;
	DampedDoubleSpringComponent& operator=(const DampedDoubleSpringComponent&) = default;

	DampedDoubleSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& dampling, const float& default_length);

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
};