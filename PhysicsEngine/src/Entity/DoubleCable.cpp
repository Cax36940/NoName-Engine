#include "DoubleCable.hpp"

void DoubleCable::update(const float& delta) {
	sprite.set_positions(cable.get_first_position(), cable.get_second_position());
}