#pragma once
#include "Vector3.hpp"
#include "Sphere.hpp"
#include "Particle.hpp"

class TrailParticle
{
private:
	Particle particle;
	std::vector<Sphere> trail;
	int space;
	int space_counter = 0;

public:
	TrailParticle() = default;
	TrailParticle(Vector3& pos, Vector3& vel, Vector3& acc, float weight);
	TrailParticle(Particle& particle);

	void set_body_size(float s);
	void set_space(float s);

	void update(float delta);
	void draw();
};