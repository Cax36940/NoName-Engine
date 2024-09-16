#include "FireBall.hpp"
#include <ofGraphics.h>


void FireBall::draw()
{
	sprite.set_position(particle.get_position());
	sprite.draw();
}


