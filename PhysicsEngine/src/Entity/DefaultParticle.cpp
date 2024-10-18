#include "DefaultParticle.hpp"

DefaultParticle::DefaultParticle(const Particle& particle, const Sphere& sphere)
	: particle(particle), sprite(sphere)
{
	//collider = SphereCollider(particle.get_position(), sprite.get_size());
}

void DefaultParticle::update(const float& delta) {
	particle.update(delta);
	sprite.set_position(particle.get_position());
	//collider.set_position(particle.get_position());
}