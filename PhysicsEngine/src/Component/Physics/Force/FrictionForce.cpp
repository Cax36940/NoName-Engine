#include "FrictionForce.hpp"

void FrictionForce::update_force(Particle* particle, float duration)
{
	// Static friction
	Vector3 perp_n_g = Vector3::cross(normal, gravity);
	Vector3 dir_f_s = Vector3::normalize(Vector3::cross(perp_n_g, normal));
	float magnitude_f_s = Vector3::dot(normal, gravity);
	Vector3 f_s = coef_static_friction * magnitude_f_s * dir_f_s;
	particle->add_force(f_s);

	// Cinetic friction
	float velocity_magnitude = Vector3::norm(particle->get_velocity());
	Vector3 f_k = -1. * particle->get_velocity() * (coef_cinetic_friction_1 * velocity_magnitude + coef_cinetic_friction_2 * velocity_magnitude * velocity_magnitude);
	particle->add_force(f_k);
}