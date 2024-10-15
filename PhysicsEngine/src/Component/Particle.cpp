#include <of3dGraphics.h>
#include "Particle.hpp"

#include <iostream>

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, const float& mass)
	: position(pos)
	, velocity(vel)
	, acceleration(acc)
	, inv_mass(1 / mass)
	, accum_force(Vector3(0,0,0)) {}

Vector3 Particle::get_position() const
{
	return position;
}

float Particle::get_mass() const
{
	return 1 / inv_mass;
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

void Particle::apply_forces_euler()
{
	// F = m*a -> a = F * (1/m)
	acceleration = accum_force * inv_mass;
}

void Particle::set_position(Vector3 pos)
{
	this->position = pos;
}

