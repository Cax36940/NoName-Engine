#include "DampedDoubleSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"

DampedDoubleSpringComponent::DampedDoubleSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& damping, const float& default_length) :
	first(first), 
	second(second),
	first_force(stiffness, damping, default_length),
	second_force(stiffness, damping, default_length){}

Vector3 DampedDoubleSpringComponent::get_first_position() const
{
	return first->get_position();
}

Vector3 DampedDoubleSpringComponent::get_second_position() const
{
	return second->get_position();
}

void DampedDoubleSpringComponent::register_physics()
{
	first_force.set_origin(second->get_position());
	second_force.set_origin(first->get_position());
	ParticleForceRegistry::add(first, (ParticleForceGenerator*)&first_force);
	ParticleForceRegistry::add(second, (ParticleForceGenerator*)&second_force);
}
