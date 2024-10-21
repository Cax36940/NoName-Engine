#pragma once
#include "DefaultParticle.hpp"

enum ParticleType {
	FIREBALL,
	TENNISBALL,
	GOLFBALL,
	LASER,
	STATIC,
	FIX,
	PARTICLE_TYPE_COUNT
};

class ParticleFactory
{
public:
	static DefaultParticle createParticle(ParticleType particle_type, const Vector3& pos, const Vector3& acc);
	static DefaultParticle createSimpleParticle(const Vector3& pos);
	static DefaultParticle createFixParticle(const Vector3& pos);
};

