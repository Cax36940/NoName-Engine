#include "BungeeSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"

BungeeSpringComponent::BungeeSpringComponent(Particle* particle, const float& stiffness, const float& default_length, const Vector3& fixed_point) : particle(particle), spring_force(stiffness, 0, default_length, fixed_point, true) {}

Vector3 BungeeSpringComponent::get_origin() const {
	return spring_force.get_origin();
}

Particle& BungeeSpringComponent::get_particle() const {
	return *particle;
}

void BungeeSpringComponent::change_fixed_point(const Vector3& new_fixed_point)
{
	spring_force.set_origin(new_fixed_point);
}

void BungeeSpringComponent::register_physics()
{
	ParticleForceRegistry::add(particle, (ParticleForceGenerator*)&spring_force);
}
