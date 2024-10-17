#include "DampedSimpleSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"

DampedSimpleSpringComponent::DampedSimpleSpringComponent(Particle* particle, const float& stiffness, const float& dampling, const float& default_length, const Vector3& fixed_point) : particle(particle), spring_force(stiffness, dampling, default_length, fixed_point){}

Vector3 DampedSimpleSpringComponent::get_origin() const {
	return spring_force.get_origin();
}

Particle& DampedSimpleSpringComponent::get_particle() const {
	return *particle;
}

void DampedSimpleSpringComponent::change_fixed_point(const Vector3& new_fixed_point)
{
	spring_force.set_origin(new_fixed_point);
}

void DampedSimpleSpringComponent::register_physics()
{
	ParticleForceRegistry::add(particle, (ParticleForceGenerator*) &spring_force);
}
