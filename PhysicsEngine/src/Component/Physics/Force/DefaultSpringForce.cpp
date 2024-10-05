#include "DefaultSpringForce.hpp"

DefaultSpringForce::DefaultSpringForce(const float stiffness, const float default_length, const Vector3& origin) : stiffness(stiffness), default_length(default_length), origin(origin) {}

void DefaultSpringForce::updateForce(Particle* particle, float duration)
{

	Vector3 force{};

	particle->add_force(force);
}
