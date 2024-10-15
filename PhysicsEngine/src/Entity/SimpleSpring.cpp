#include "SimpleSpring.hpp"

void SimpleSpring::update(const float& delta) {
	sprite.set_positions(spring.get_origin(), spring.get_particle().get_position());
}