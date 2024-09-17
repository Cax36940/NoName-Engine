#pragma once
#include "DefaultParticle.hpp"

enum ParticleType {
	FIREBALL,
	TENNISBALL,
	GOLFBALL,
	PARTICLE_TYPE_COUNT
};

class ParticleFactory
{
public:
	static DefaultParticle createParticle(ParticleType particle_type, const Vector3& pos, const Vector3& acc);
};

