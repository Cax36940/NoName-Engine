#pragma once
#include "Component/Particle.hpp"

class ParticleForceGenerator
{
public:
	virtual void update_force(Particle* particle, float duration) = 0;
};
