#include "SimpleSpringComponent.hpp"

SimpleSpringComponent::SimpleSpringComponent(Vector3 fixed_point, Particle* particle) : fixed_point(fixed_point), particle(particle) {}

void SimpleSpringComponent::registerPhysics()
{
	// SpringForce.updateForce(first, delta)
}
