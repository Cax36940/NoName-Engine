#include "DoubleSpring.hpp"

void DoubleSpring::update(const float& delta) {
	sprite.set_positions(spring.get_first_position(), spring.get_second_position());
}