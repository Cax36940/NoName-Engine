#include "Particle.hpp"
#include <of3dGraphics.h>

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, const float& weight)
	: position(pos)
	, velocity(vel)
	, acceleration(acc)
	, weight(weight) {}

Vector3 Particle::get_position() const
{
	return position;
}

void Particle::update(const float& delta)
{
	velocity = velocity + acceleration * delta;
	position = position + velocity * delta;
}

