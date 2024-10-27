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
	float rigid_coeff; // If true the spring does not elongate more than its rigid_coeff * length

public:
	DampedDoubleSpringComponent() = default;
	DampedDoubleSpringComponent(const DampedDoubleSpringComponent&) = default;
	DampedDoubleSpringComponent& operator=(const DampedDoubleSpringComponent&) = default;

	DampedDoubleSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& damping, const float& default_length, const float rigid_coeff = -1.0f, const bool is_bungee = false);

	Vector3 get_first_position() const;
	Vector3 get_second_position() const;

	void register_physics() override;
	void register_rigid_physics();

};