#pragma once
#include "ParticleForceGenerator.hpp"

class DefaultSpringForce : ParticleForceGenerator {
private:
	float stiffness;
	float default_length;
	Vector3 origin;

public:
	DefaultSpringForce() = default;
	DefaultSpringForce(const DefaultSpringForce&) = default;
	DefaultSpringForce& operator=(const DefaultSpringForce&) = default;

	DefaultSpringForce(const float& stiffness, const float& default_length);
	DefaultSpringForce(const float& stiffness, const float& default_length, const Vector3& origin);

	void set_origin(const Vector3& new_origin);
	Vector3 get_origin() const;
	float get_default_length() const;
	void update_force(Particle* particle, float duration) override;
};