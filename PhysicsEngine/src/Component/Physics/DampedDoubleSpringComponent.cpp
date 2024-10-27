#include "DampedDoubleSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "System/CollisionsRegistry.hpp"

DampedDoubleSpringComponent::DampedDoubleSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& damping, const float& default_length, const float rigid_coeff, const bool is_bungee) :
	first(first), 
	second(second),
	first_force(stiffness, damping, default_length, is_bungee),
	second_force(stiffness, damping, default_length, is_bungee),
	rigid_coeff(rigid_coeff){}

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
	if (rigid_coeff > 0.0f) {
		register_rigid_physics();
		return;
	}

	first_force.set_origin(second->get_position());
	second_force.set_origin(first->get_position());
	ParticleForceRegistry::add(first, (ParticleForceGenerator*)&first_force);
	ParticleForceRegistry::add(second, (ParticleForceGenerator*)&second_force);
}

void DampedDoubleSpringComponent::register_rigid_physics()
{

	const Vector3 vector_ji = first->get_position() - second->get_position();
	const float norm2_ij = Vector3::norm2(vector_ji);

	// If the spring extends more than first_force.get_default_length() * rigid_coeff it acts as a cable
	if (norm2_ij <= first_force.get_default_length() * first_force.get_default_length() * rigid_coeff * rigid_coeff) {
		first_force.set_origin(second->get_position());
		second_force.set_origin(first->get_position());
		ParticleForceRegistry::add(first, (ParticleForceGenerator*)&first_force);
		ParticleForceRegistry::add(second, (ParticleForceGenerator*)&second_force);
	}
	else {

		const float norm_ij = std::sqrt(norm2_ij);
		const Vector3 normal = vector_ji * (1 / norm_ij);

		// Compute the distance to separate both objects
		const float collision_distance = first_force.get_default_length() * rigid_coeff - norm_ij;

		const float m1 = first->get_mass();
		const float m2 = second->get_mass();

		const Vector3 delta_position1 = (collision_distance * m2 / (m1 + m2)) * normal;
		const Vector3 delta_position2 = (-collision_distance * m1 / (m1 + m2)) * normal;


		// Compute the change in velocity for both objects
		const Vector3 v_relative = first->get_velocity() - second->get_velocity();
		const float k = (0.1 + 1) * Vector3::dot(v_relative, normal) / (first->get_inv_mass() + second->get_inv_mass());
		const Vector3 delta_velocity1 = (-k * first->get_inv_mass()) * normal;
		const Vector3 delta_velocity2 = (k * second->get_inv_mass()) * normal;


		CollisionsRegistry::add(first, delta_position1, delta_velocity1);
		CollisionsRegistry::add(second, delta_position2, delta_velocity2);
	}
}