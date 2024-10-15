#include "DefaultSpringForce.hpp"

DefaultSpringForce::DefaultSpringForce(const float stiffness, const float default_length) : stiffness(stiffness), default_length(default_length), origin(0,0,0) {}
DefaultSpringForce::DefaultSpringForce(const float stiffness, const float default_length, const Vector3& origin) : stiffness(stiffness), default_length(default_length), origin(origin) {}

void DefaultSpringForce::updateForce(Particle* particle, float duration)
{
	Vector3 force = particule.get_position() - origin;
	Vector3 unit_vector = Vector3::normalize(force);
	float length = Vector3::norm(force);

	force = (-stiffness * length) * unit_vector;

	particle->add_force(force);
}
