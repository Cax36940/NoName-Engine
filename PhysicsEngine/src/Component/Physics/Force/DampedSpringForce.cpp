#include "DampedSpringForce.hpp"

DampedSpringForce::DampedSpringForce(const float& stiffness, const float& dampling, const float& default_length) : stiffness(stiffness), dampling(dampling), default_length(default_length), origin(0,0,0) {}
DampedSpringForce::DampedSpringForce(const float& stiffness, const float& dampling, const float& default_length, const Vector3& origin) : stiffness(stiffness), dampling(dampling), default_length(default_length), origin(origin) {}

void DampedSpringForce::set_origin(const Vector3& new_origin)
{
	origin = new_origin;
}

Vector3 DampedSpringForce::get_origin() const
{
	return origin;
}

void DampedSpringForce::update_force(Particle* particle, float duration)
{
	Vector3 force = particle->get_position() - origin;
	Vector3 unit_vector = Vector3::normalize(force);
	float length = Vector3::norm(force);

	force = ((-stiffness * (length - default_length)) * unit_vector) - dampling * particle->get_velocity();

	particle->add_force(force);
}
