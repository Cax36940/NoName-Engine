#pragma once

#include "Vector3.hpp"

class Particle {
private:
	// Physics related
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	float inv_mass;

public:
	Particle() = default;
	Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, const float& mass);

	Vector3 get_position() const;

	void update(const float& delta);
};