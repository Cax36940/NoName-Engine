#include "BungeeSpringForce.hpp"

BungeeSpringForce::BungeeSpringForce(const float& stiffness, const float& default_length) : stiffness(stiffness), default_length(default_length), origin(0, 0, 0) {}
BungeeSpringForce::BungeeSpringForce(const float& stiffness, const float& default_length, const Vector3& origin) : stiffness(stiffness), default_length(default_length), origin(origin) {}

void BungeeSpringForce::set_origin(const Vector3& new_origin)
{
	origin = new_origin;
}

Vector3 BungeeSpringForce::get_origin() const
{
	return origin;
}

void BungeeSpringForce::update_force(Particle* particle, float duration)
{
	Vector3 force = particle->get_position() - origin;
	Vector3 unit_vector = Vector3::normalize(force);
	float length = Vector3::norm(force);

	force = (-stiffness * std::min(0.f,(length - default_length))) * unit_vector;

	particle->add_force(force);
}
