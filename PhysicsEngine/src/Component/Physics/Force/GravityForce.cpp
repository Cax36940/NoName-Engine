#include "GravityForce.hpp"

GravityForce::GravityForce()
	: gravity(0.0)
{
}

GravityForce::GravityForce(float gravity_strength)
	: gravity(gravity_strength)
{
}

void GravityForce::updateForce(Particle* particle, float duration)
{
	particle->add_force(Vector3(0, gravity * particle->get_mass(), 0));
}
