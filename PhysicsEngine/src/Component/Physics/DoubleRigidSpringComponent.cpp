#include "DoubleRigidSpringComponent.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "System/CollisionsRegistry.hpp"

#define MAX_EXPAND_COEF 1.5

DoubleRigidSpringComponent::DoubleRigidSpringComponent(Particle* first, Particle* second, const float& stiffness, const float& default_length) :
	first(first), 
	second(second),
	first_force(stiffness, default_length),
	second_force(stiffness, default_length){}

Vector3 DoubleRigidSpringComponent::get_first_position() const
{
	return first->get_position();
}

Vector3 DoubleRigidSpringComponent::get_second_position() const
{
	return second->get_position();
}

void DoubleRigidSpringComponent::register_physics()
{

	const Vector3 vector_ji = first->get_position() - second->get_position();
	const float norm2_ij = Vector3::norm2(vector_ji);

	// If the spring extends more than first_force.get_default_length() * MAX_EXPAND_COEF it acts as a cable
	if (norm2_ij < first_force.get_default_length() * first_force.get_default_length() * MAX_EXPAND_COEF * MAX_EXPAND_COEF) {
		first_force.set_origin(second->get_position());
		second_force.set_origin(first->get_position());
		ParticleForceRegistry::add(first, (ParticleForceGenerator*)&first_force);
		ParticleForceRegistry::add(second, (ParticleForceGenerator*)&second_force);
	} else {

		const float norm_ij = std::sqrt(norm2_ij);
		const Vector3 normal = vector_ji * (1 / norm_ij);

		// Compute the distance to separate both objects
		const float collision_distance = first_force.get_default_length() * MAX_EXPAND_COEF - norm_ij;

		const float m1 = first->get_mass();
		const float m2 = second->get_mass();

		const Vector3 delta_position1 = (collision_distance * m2 / (m1 + m2)) * normal;
		const Vector3 delta_position2 = (-collision_distance * m1 / (m1 + m2)) * normal;


		// Compute the change in velocity for both objects
		const Vector3 v_relative = first->get_velocity() - second->get_velocity();
		const float k = (2 * Vector3::dot(v_relative, normal)) / (first->get_inv_mass() + second->get_inv_mass());
		const Vector3 delta_velocity1 = (-k * first->get_inv_mass()) * normal;
		const Vector3 delta_velocity2 = (k * second->get_inv_mass()) * normal;


		CollisionsRegistry::add(first, delta_position1, delta_velocity1);
		CollisionsRegistry::add(second, delta_position2, delta_velocity2);
	}
}
