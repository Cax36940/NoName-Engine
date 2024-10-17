#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DampedSpringForce.hpp"
#include "PhysicsComponent.hpp"

class DampedSimpleSpringComponent : public PhysicsComponent {
private :
	Particle* particle;
	DampedSpringForce spring_force;

public :
	DampedSimpleSpringComponent() = default;
	DampedSimpleSpringComponent(const DampedSimpleSpringComponent&) = default;
	DampedSimpleSpringComponent& operator=(const DampedSimpleSpringComponent&) = default;

	DampedSimpleSpringComponent(Particle* particle, const float& stiffness, const float& dampling, const float& default_length, const Vector3& fixed_point);

	void change_fixed_point(const Vector3& new_fixed_point);

	Vector3 get_origin() const;
	Particle& get_particle() const;

	void register_physics() override;
};