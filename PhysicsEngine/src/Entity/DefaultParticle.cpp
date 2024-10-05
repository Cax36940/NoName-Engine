#include "DefaultParticle.hpp"

void DefaultParticle::update(const float& delta) {
	particle.update(delta);
	sprite.set_position(particle.get_position());
}