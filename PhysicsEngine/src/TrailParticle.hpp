#pragma once
#include "Vector3.hpp"
#include "Sphere.hpp"
#include "DefaultParticle.hpp"

class TrailParticle
{
private:
	DefaultParticle *particle;
	std::vector<Sphere> trail;
	int space;
	int space_counter = 0;

public:
	TrailParticle() = default;
	TrailParticle(DefaultParticle* particle);

	void set_space(float s);

	void update(float delta);
	void draw();
	void drawSingleParticle();
	
};