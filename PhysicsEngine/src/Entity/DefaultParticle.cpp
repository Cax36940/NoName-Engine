#include "DefaultParticle.hpp"

DefaultParticle::DefaultParticle(const Particle& _particle, const Sphere& sphere)
	: particle(_particle), sprite(sphere), collider(sprite.get_size(), &particle){}

void DefaultParticle::update(const float& delta) {
	particle.update(delta);
	sprite.set_position(particle.get_position());
}