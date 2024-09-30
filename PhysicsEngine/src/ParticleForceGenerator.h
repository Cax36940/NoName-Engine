#pragma once
#include "Particle.hpp"

// interface (pas de .cpp)
class ParticleForceGenerator
{
public:
	virtual void updateForce(Particle* particle, float duration) = 0;
};
