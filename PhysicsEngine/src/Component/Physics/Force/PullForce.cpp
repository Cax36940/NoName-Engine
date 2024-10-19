#include "PullForce.hpp"

void PullForce::set_position(const Vector3& new_position)
{
	position = new_position;
}

void PullForce::update_force(Particle* particle, float duration)
{
	particle->add_force(magnitude * (position - particle->get_position()));
}
