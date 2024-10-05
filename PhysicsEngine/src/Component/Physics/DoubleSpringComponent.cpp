#include "DoubleSpringComponent.hpp"

DoubleSpringComponent::DoubleSpringComponent(Particle* first, Particle* second) : first(first), second(second) {}

void DoubleSpringComponent::registerPhysics()
{
	// SpringForce.updateForce(first, delta)
	// SpringForce.updateForce(second, delta)
}
