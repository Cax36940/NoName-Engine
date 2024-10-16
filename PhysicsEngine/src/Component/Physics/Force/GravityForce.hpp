#pragma once
#include "ParticleForceGenerator.hpp"

class GravityForce : public ParticleForceGenerator
{
private:
	float gravity;

public:
	GravityForce();
	GravityForce(float gravity_strength);

	void updateForce(Particle* particle, float duration) override;
};