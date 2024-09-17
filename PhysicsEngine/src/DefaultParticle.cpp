#include "DefaultParticle.hpp"

void DefaultParticle::draw() {
	sprite.set_position(particle.get_position());
	sprite.draw();
}

void DefaultParticle::update(const float& delta) {
	particle.update(delta);
}