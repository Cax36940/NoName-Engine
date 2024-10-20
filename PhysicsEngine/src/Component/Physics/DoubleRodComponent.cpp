#include "DoubleRodComponent.hpp"
#include "System/CollisionsRegistry.hpp"

Vector3 DoubleRodComponent::get_first_position() const
{
	return first->get_position();
}

Vector3 DoubleRodComponent::get_second_position() const
{
	return second->get_position();
}

void DoubleRodComponent::register_physics()
{
	const Vector3 vector_ji = first->get_position() - second->get_position();

	const float norm_ij = Vector3::norm(vector_ji);
	const Vector3 normal = vector_ji * (1 / norm_ij);

	// Compute the distance to separate both objects
	const float collision_distance = default_length - norm_ij;

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
