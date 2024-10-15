#include <of3dGraphics.h>
#include "Particle.hpp"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, const float& mass)
	: position(pos)
	, velocity(vel)
	, acceleration(acc)
	, inv_mass(1 / mass)
	, accum_force(Vector3()) {}

Vector3 Particle::get_position() const
{
	return position;
}

void Particle::update(const float& delta)
{
	velocity = velocity + acceleration * delta;
	position = position + velocity * delta; //intégration d'Euler
}

void Particle::add_force(const Vector3 &force)
{
	accum_force += force;
}

void Particle::clear_accum()
{
	accum_force = Vector3(0,0,0);
}

void Particle::set_position(Vector3 pos)
{
	this->position = pos;
}

