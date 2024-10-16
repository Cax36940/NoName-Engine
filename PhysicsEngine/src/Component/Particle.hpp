#pragma once

#include "Vector3.hpp"

class Particle {
private:
	// Physics related
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	float inv_mass;

	// forces résultantes (d'Alembert)
	Vector3 accum_force;

public:
	Particle() = default;
	Particle(const Particle&) = default;
	Particle& operator=(const Particle&) = default;
	Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, const float& mass);

	Vector3 get_position() const;
	float get_mass() const;

	void update(const float& delta);


	void add_force(const Vector3 &force);
	void clear_accum();
	void apply_forces_euler();

	void set_position(const Vector3& new_position);
	void set_velocity(const Vector3& new_velocity);
};