#include "ParticleFactory.hpp"

static struct ParticleArgs {
	Vector3 velocity;
	float mass;
	float size;
	Vector3 color;
};

static ParticleArgs particle_args_list[] = {
 {Vector3(100, -250, 0), 250, 20, Vector3(255, 100,   0)},	// FIREBALL
 {Vector3(150, -100, 0),  50, 10, Vector3(200, 200,   0)},	// TENNISBALL
 {Vector3(350,  -70, 0),  10,  5, Vector3(200, 200, 200)},	// GOLFBALL
 {Vector3(1000,  -1000, 0), 1, 15, Vector3(255, 0, 0)},		// LASER
 {Vector3(0, 0, 0), 1, 10, Vector3(255, 255, 255)},			// STATIC
 {Vector3(0, 0, 0), 10000000, 0, Vector3(0, 0, 0)}			// FIX
};

DefaultParticle ParticleFactory::createParticle(ParticleType particle_type, const Vector3& pos, const Vector3& acc) {
	const ParticleArgs& particle_args = particle_args_list[particle_type];
	return DefaultParticle(Particle(pos, particle_args.velocity, acc, particle_args.mass), Sphere(particle_args.size, particle_args.color));
}

DefaultParticle ParticleFactory::createSimpleParticle(const Vector3& pos) {
	return createParticle(STATIC, pos, Vector3(0,0,0));
}

DefaultParticle ParticleFactory::createFixParticle(const Vector3& pos)
{
	return createParticle(FIX, pos, Vector3(0, 0, 0));
}
