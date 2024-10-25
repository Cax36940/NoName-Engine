#pragma once
#include "ParticleForceGenerator.hpp"

class DampedSpringForce : ParticleForceGenerator {
private:
	float stiffness;
	float damping;
	float default_length;
	Vector3 origin;
	bool is_bungee;

public:
	DampedSpringForce() = default;
	DampedSpringForce(const DampedSpringForce&) = default;
	DampedSpringForce& operator=(const DampedSpringForce&) = default;

	DampedSpringForce(const float& stiffness, const float& damping, const float& default_length, const bool is_bungee = false);
	DampedSpringForce(const float& stiffness, const float& damping, const float& default_length, const Vector3& origin, const bool is_bungee = false);

	void set_origin(const Vector3& new_origin);
	Vector3 get_origin() const;
	float get_default_length() const;
	void update_force(Particle* particle, float duration) override;
};