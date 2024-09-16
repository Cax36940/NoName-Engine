#include "Particle.hpp"
#include <of3dGraphics.h>

Particle::Particle(Vector3& pos, Vector3& vel, Vector3& acc, float weight)
	: position(pos)
	, velocity(vel)
	, acceleration(acc)
	, weight(weight)
{
}

Vector3 Particle::get_position() const
{
	return position;
}


void Particle::update(float delta)
{
	velocity = velocity + acceleration * delta;
	position = position + velocity * delta;
}

