#pragma once
#include "Component/Graphics/Sphere.hpp"
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
	TrailParticle(const TrailParticle&) = default;
	TrailParticle& operator=(const TrailParticle&) = default;
	TrailParticle(const DefaultParticle& particle);

	void set_space(const float& s);

	void update(const float& delta);
	void clearTrail();
};