#include "Particle.hpp"
#include <of3dGraphics.h>

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, const float& mass)
	: position(pos)
	, velocity(vel)
	, acceleration(acc)
	, inv_mass(1 / mass) {}

Vector3 Particle::get_position() const
{
	return position;
}

void Particle::update(const float& delta)
{
	velocity = velocity + acceleration * delta;
	position = position + velocity * delta; //int�gration d'Euler
}

void Particle::add_force(const Vector3 &force)
{
	accum_force += force;
}

void Particle::clear_accum()
{
	accum_force = Vector3(0,0,0);
}

