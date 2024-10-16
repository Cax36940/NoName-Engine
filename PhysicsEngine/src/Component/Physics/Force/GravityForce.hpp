#pragma once
#include "ParticleForceGenerator.hpp"

class GravityForce : public ParticleForceGenerator
{
private:
	float gravity;

public:
	GravityForce() : gravity(0.0) {}
	GravityForce(const GravityForce&) = default;
	GravityForce& operator=(const GravityForce&) = default;

	GravityForce::GravityForce(float gravity_strength) : gravity(gravity_strength) {}

	void update_force(Particle* particle, float duration) override;
};