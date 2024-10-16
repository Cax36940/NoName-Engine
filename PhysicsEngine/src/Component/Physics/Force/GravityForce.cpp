#include "GravityForce.hpp"

void GravityForce::update_force(Particle* particle, float duration)
{
	particle->add_force(Vector3(0, gravity * particle->get_mass(), 0));
}
