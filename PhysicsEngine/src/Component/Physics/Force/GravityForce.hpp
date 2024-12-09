#pragma once
#include "ParticleForceGenerator.hpp"

#define GRAVITY_VALUE -10

class GravityForce : public ParticleForceGenerator
{
private:
	GravityForce() = default;

public:
	GravityForce(const GravityForce&) = delete;
	GravityForce& operator=(const GravityForce&) = delete;

	static GravityForce& get_instance() {
		static GravityForce gravity;
		return gravity;
	}

	float get_value() {
		return GRAVITY_VALUE;
	}

	void update_force(Particle* particle, float duration) override {
		particle->add_force(Vector3(0, GRAVITY_VALUE * particle->get_mass(), 0));
	};
};
