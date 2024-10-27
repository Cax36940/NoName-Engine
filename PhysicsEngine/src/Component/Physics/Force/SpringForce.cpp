#include "SpringForce.hpp"

SpringForce::SpringForce(const float& stiffness, const float& damping, const float& default_length, const bool is_bungee) : stiffness(stiffness), damping(damping), default_length(default_length), origin(0,0,0), is_bungee(is_bungee) {}
SpringForce::SpringForce(const float& stiffness, const float& damping, const float& default_length, const Vector3& origin, const bool is_bungee) : stiffness(stiffness), damping(damping), default_length(default_length), origin(origin), is_bungee(is_bungee) {}

void SpringForce::set_origin(const Vector3& new_origin)
{
	origin = new_origin;
}

Vector3 SpringForce::get_origin() const
{
	return origin;
}

float SpringForce::get_default_length() const
{
	return default_length;
}

void SpringForce::update_force(Particle* particle, float duration)
{
	Vector3 force = particle->get_position() - origin;
	float length = Vector3::norm(force);
	const Vector3 unit_vector = force * (1/length);
	
	length -=default_length;

	if (is_bungee && length < 0) {
		return; // Apply no force
	}

	force = ((-stiffness * length) * unit_vector) - damping * particle->get_velocity();

	particle->add_force(force);
}
