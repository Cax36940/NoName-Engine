#pragma once
#include "Vector3.hpp"
#include "Sphere.hpp"
#include "DefaultParticle.hpp"

class TrailParticle
{
private:
	DefaultParticle particle;
	std::vector<Sphere> trail;
	int space;
	int space_counter;

public:
	TrailParticle() = default;
	TrailParticle(const DefaultParticle& particle);

	void set_space(const float& s);

	void update(const float& delta);
	void draw();
	void clearTrail();
	
};