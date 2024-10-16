#include "SimpleSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"

SimpleSpringComponent::SimpleSpringComponent(Particle* particle, const float& stiffness, const float& default_length, const Vector3& fixed_point) : particle(particle), spring_force(stiffness, default_length, fixed_point){}

Vector3 SimpleSpringComponent::get_origin() const {
	return spring_force.get_origin();
}

Particle& SimpleSpringComponent::get_particle() const {
	return *particle;
}

void SimpleSpringComponent::change_fixed_point(const Vector3& new_fixed_point)
{
	spring_force.set_origin(new_fixed_point);
}

void SimpleSpringComponent::register_physics()
{
	ParticleForceRegistry::add(particle, (ParticleForceGenerator*) &spring_force);
}
