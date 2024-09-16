#include "DefaultParticle.hpp"

void DefaultParticle::draw() {
	sprite.draw();
}

void DefaultParticle::update(float delta) {
	particle.update(delta);
}