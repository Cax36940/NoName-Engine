#include "DoubleSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"

DoubleSpringComponent::DoubleSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& default_length) : 
	first(first), 
	second(second),
	first_force(stiffness, default_length),
	second_force(stiffness, default_length){}

void DoubleSpringComponent::register_physics()
{
	first_force.set_origin(second->get_position());
	second_force.set_origin(first->get_position());
	ParticleForceRegistry::add(first, (ParticleForceGenerator*)&first_force);
	ParticleForceRegistry::add(second, (ParticleForceGenerator*)&second_force);
}
