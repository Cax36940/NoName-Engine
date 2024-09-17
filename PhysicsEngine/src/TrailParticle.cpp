#include "TrailParticle.hpp"

TrailParticle::TrailParticle(Vector3& pos, Vector3& vel, Vector3& acc, float weight)
	: TrailParticle(Particle(pos, vel, acc, weight))
{}

TrailParticle::TrailParticle(Particle& p)
	: particle(p)
{
	this->space = 0;
}

void TrailParticle::set_body_size(float s)
{
	this->particle.set_size(s);
}

void TrailParticle::set_space(float s)
{
	this->space = s;
}

void TrailParticle::update(float delta)
{
	if (this->space == this->space_counter)
	{
		Sphere trail_dot = Sphere(
			particle.get_position(),
			3
		);
		trail.push_back(trail_dot);
		this->space_counter = 0;
	}
	else {
		this->space_counter++;
	}

	particle.update(delta);
}

void TrailParticle::draw()
{
	for each (Sphere dot in trail)
	{
		dot.draw();
	}
	particle.draw();
}

void TrailParticle::drawSingleParticle()
{
	particle.drawSingleParticle();
}
