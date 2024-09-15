#include "TrailParticle.hpp"

TrailParticle::TrailParticle(Vector3& pos, Vector3& vel, Vector3& acc, float weight)
	: Particle(pos, vel, acc, weight)
{
	this->space = 0;
}

void TrailParticle::set_space(float s)
{
	this->space = s;
}

void TrailParticle::update(float delta)
{
	if (this->space == this->space_counter)
	{
		Particle static_particle = Particle(
			Particle::get_position(),
			Vector3(0, 0, 0),
			Vector3(0, 0, 0),
			1
		);
		static_particle.set_size(3);
		trail.push_back(static_particle);
		this->space_counter = 0;
	}
	else {
		this->space_counter++;
	}

	Particle::update(delta);
}

void TrailParticle::draw()
{
	for each (Particle sp in trail)
	{
		sp.draw();
	}
	Particle::draw();
}
