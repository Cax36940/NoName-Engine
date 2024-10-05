#include "TrailParticle.hpp"

TrailParticle::TrailParticle(const DefaultParticle& p)
	: particle(p)
{
	this->space = 10;
	this->space_counter = 0;
}

void TrailParticle::set_space(const float& s)
{
	this->space = s;
}

void TrailParticle::update(const float& delta)
{
	if (this->space == this->space_counter)
	{
		Sphere trail_dot(particle.sprite);
		trail_dot.set_size(3);
		trail.push_back(trail_dot);
		this->space_counter = 0;
	}
	else {
		this->space_counter++;
	}

	particle.update(delta);
}

void TrailParticle::clearTrail()
{
	this->trail.clear();
}

