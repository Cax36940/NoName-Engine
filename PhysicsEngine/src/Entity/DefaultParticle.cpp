#include "DefaultParticle.hpp"

DefaultParticle::DefaultParticle(const Particle& _particle, const Sphere& sphere)
	: particle(_particle), sprite(sphere)
{
	collider = SphereCollider(particle.get_position(), sprite.get_size(), &particle);
}

void DefaultParticle::update(const float& delta) {
	particle.update(delta);
	sprite.set_position(particle.get_position());
	collider.set_position(particle.get_position());
}