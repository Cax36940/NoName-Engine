#pragma once
#include "Component/Particle.hpp"
#include "Component/Physics/Force/BungeeSpringForce.hpp"
#include "PhysicsComponent.hpp"

class BungeeSpringComponent : public PhysicsComponent {
private:
	Particle* particle;
	BungeeSpringForce spring_force;

public:
	BungeeSpringComponent() = default;
	BungeeSpringComponent(const BungeeSpringComponent&) = default;
	BungeeSpringComponent& operator=(const BungeeSpringComponent&) = default;

	BungeeSpringComponent(Particle* particle, const float& stiffness, const float& default_length, const Vector3& fixed_point);

	void change_fixed_point(const Vector3& new_fixed_point);

	Vector3 get_origin() const;
	Particle& get_particle() const;

	void register_physics() override;
};