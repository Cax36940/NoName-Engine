#pragma once
#include "ParticleForceGenerator.hpp"

class PullForce : public ParticleForceGenerator
{
private:
	float magnitude;
	Vector3 position;

public:
	PullForce() = default;
	PullForce(const PullForce&) = default;
	PullForce& operator=(const PullForce&) = default;

	PullForce(float magnitude, const Vector3& position) : magnitude(magnitude), position(position){}

	void set_position(const Vector3& new_position);

	void update_force(Particle* particle, float duration) override;
};