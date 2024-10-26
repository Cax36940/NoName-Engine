#include "DefaultParticle.hpp"

DefaultParticle::DefaultParticle(const Particle& _particle, const Sphere& sphere)
	: particle(_particle), sprite(sphere), collider(sprite.get_size(), &particle){}

void DefaultParticle::update(float delta) {
	sprite.set_position(particle.get_position());
}