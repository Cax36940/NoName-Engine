#include "FrictionForce.hpp"
#include "GravityForce.hpp"

void FrictionForce::update_force(Particle* particle, float duration)
{
	const Vector3 p_velocity = particle->get_velocity() - Vector3::dot(particle->get_velocity(), normal) * normal;
	const float velocity_magnitude = Vector3::norm(p_velocity);

	// Static friction
	// Cross(normal, gravity)
	if (velocity_magnitude < 10E-6) {
		/*const Vector3 perp_n_g(-GravityForce::get_instance().get_value() * normal.z, 0, GravityForce::get_instance().get_value() * normal.x);
		const Vector3 dir_f_s = Vector3::normalize(Vector3::cross(normal, perp_n_g));
		const float magnitude_f_s = normal.y * GravityForce::get_instance().get_value();
		const Vector3 f_s = coef_static_friction * magnitude_f_s * dir_f_s;
		particle->add_force(f_s);*/
		return;
	}

	// Cinetic friction
	const Vector3 f_k = -1. * Vector3::normalize(p_velocity) * (coef_cinetic_friction_1 * velocity_magnitude + coef_cinetic_friction_2 * velocity_magnitude * velocity_magnitude);
	particle->add_force(f_k);
}