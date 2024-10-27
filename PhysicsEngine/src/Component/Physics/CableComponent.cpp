#include "CableComponent.hpp"
#include "System/CollisionsRegistry.hpp"

Vector3 CableComponent::get_first_position() const
{
	return first->get_position();
}

Vector3 CableComponent::get_second_position() const
{
	return second->get_position();
}

void CableComponent::register_physics()
{
	const Vector3 vector_ji = first->get_position() - second->get_position();
	const float norm2_ij = Vector3::norm2(vector_ji);
	if (is_rigid || norm2_ij >= default_length * default_length) {

		const float norm_ij = std::sqrt(norm2_ij);
		const Vector3 normal = vector_ji * (1 / norm_ij);

		// Compute the distance to separate both objects
		const float collision_distance = default_length - norm_ij;

		const float m1 = first->get_mass();
		const float m2 = second->get_mass();

		const Vector3 delta_position1 = ( collision_distance * m2 / (m1 + m2)) * normal;
		const Vector3 delta_position2 = (-collision_distance * m1 / (m1 + m2)) * normal;


		// Compute the change in velocity for both objects
		const Vector3 v_relative = first->get_velocity() - second->get_velocity();
		const float k = Vector3::dot(v_relative, normal) / (first->get_inv_mass() + second->get_inv_mass());
		const Vector3 delta_velocity1 = (-k * first->get_inv_mass()) * normal;
		const Vector3 delta_velocity2 = (k * second->get_inv_mass()) * normal;


		CollisionsRegistry::add(first, delta_position1, delta_velocity1);
		CollisionsRegistry::add(second, delta_position2, delta_velocity2);
	}
}
