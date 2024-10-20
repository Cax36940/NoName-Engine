#include "DoubleRod.hpp"

void DoubleRod::update(const float& delta) {
	sprite.set_positions(rod.get_first_position(), rod.get_second_position());
}