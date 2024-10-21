#include "DoubleRigidSpring.hpp"

void DoubleRigidSpring::update(const float& delta) {
	sprite.set_positions(spring.get_first_position(), spring.get_second_position());
}