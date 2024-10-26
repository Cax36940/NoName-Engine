#include "TrailParticle.hpp"

TrailParticle::TrailParticle(const DefaultParticle& p)
	: particle(p)
{
	space = 10;
	space_counter = 0;
}

void TrailParticle::set_space(const float& s)
{
	space = s;
}

void TrailParticle::update(float delta)
{
	if (space == space_counter)
	{
		Sphere trail_dot(particle.sprite);
		trail_dot.set_size(3);
		trail.push_back(trail_dot);
		space_counter = 0;
	}
	else {
		space_counter++;
	}

}

void TrailParticle::clear_trail()
{
	trail.clear();
}

