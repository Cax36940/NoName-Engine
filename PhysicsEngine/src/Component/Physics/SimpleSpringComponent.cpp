#include "SimpleSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"

SimpleSpringComponent::SimpleSpringComponent(Particle* particle, const float stiffness, const float default_length, const Vector3& fixed_point) : particle(particle), spring_force(stiffness, default_length, fixed_point){}

void SimpleSpringComponent::changeFixedPoint(const Vector3& new_fixed_point)
{
	spring_force.setOrigin(new_fixed_point);
}

void SimpleSpringComponent::registerPhysics()
{
	ParticleForceRegistry::add(particle, (ParticleForceGenerator*) &spring_force);
}
