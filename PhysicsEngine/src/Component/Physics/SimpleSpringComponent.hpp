#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/DefaultSpringForce.hpp"
#include "PhysicsComponent.hpp"

class SimpleSpringComponent : public PhysicsComponent {
private :
	Particle* particle;
	DefaultSpringForce spring_force;

public :
	SimpleSpringComponent() = default;
	SimpleSpringComponent(const SimpleSpringComponent&) = default;
	SimpleSpringComponent& operator=(const SimpleSpringComponent&) = default;

	SimpleSpringComponent(Particle* particle, const float& stiffness, const float& default_length, const Vector3& fixed_point);

	void change_fixed_point(const Vector3& new_fixed_point);

	Vector3 get_origin() const;
	Particle& get_particle() const;

	void register_physics() override;
};