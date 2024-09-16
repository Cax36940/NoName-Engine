#pragma once

#include "Vector3.hpp"

class Particle {
private:
	// Physics related
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
	float weight;

	// Rendering related
	float size;

public:
	Particle() = default;
	Particle(Vector3& pos, Vector3& vel, Vector3& acc, float weight);

	Vector3 get_position() const;
	void set_size(float s);

	void update(float delta);
	void draw();
};