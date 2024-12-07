#include <of3dGraphics.h>
#include "Particle.hpp"
#include "Physics/Force/GravityForce.hpp"
#include "System/ParticleForceRegistry.hpp"


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

const Vector3* Particle::get_position_ptr()
{
	return &position;
}

Vector3 Particle::get_velocity() const
{
	return velocity;
}

float Particle::get_mass() const
{
	return 1 / inv_mass;
}

float Particle::get_inv_mass() const
{
	return inv_mass;
}

void Particle::update(float delta)
{
	apply_forces_euler();
	velocity = velocity + acceleration * delta;
	position = position + velocity * delta;
	clear_accum();
}

void Particle::add_force(const Vector3 &force)
{
	if (apply_gravity && cancel_gravity && force.y == GravityForce::get_instance().get_value() * get_mass()) {
		cancel_gravity = false;
		return;
	}
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

void Particle::set_cancel_gravity(bool new_value)
{
	cancel_gravity = true;
}

void Particle::set_position(const Vector3& new_position)
{
	position = new_position;
}

void Particle::set_velocity(const Vector3& new_velocity)
{
	velocity = new_velocity;
}

void Particle::set_apply_gravity(bool new_value)
{
	apply_gravity = new_value;
}

void Particle::register_physics()
{
	if (apply_gravity) {
		ParticleForceRegistry::add(this, &GravityForce::get_instance());
	}
}

