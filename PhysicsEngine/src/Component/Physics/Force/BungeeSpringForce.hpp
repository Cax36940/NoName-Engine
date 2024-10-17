#pragma once
#include "ParticleForceGenerator.hpp"

class BungeeSpringForce : ParticleForceGenerator {
private:
	float stiffness;
	float default_length;
	Vector3 origin;

public:
	BungeeSpringForce() = default;
	BungeeSpringForce(const BungeeSpringForce&) = default;
	BungeeSpringForce& operator=(const BungeeSpringForce&) = default;

	BungeeSpringForce(const float& stiffness, const float& default_length);
	BungeeSpringForce(const float& stiffness, const float& default_length, const Vector3& origin);

	void set_origin(const Vector3& new_origin);
	Vector3 get_origin() const;
	void update_force(Particle* particle, float duration) override;
};