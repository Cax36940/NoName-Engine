#include "TrailParticle.hpp"

TrailParticle::TrailParticle(Vector3& pos, Vector3& vel, Vector3& acc, float weight)
	: Particle(pos, vel, acc, weight)
{
}

void TrailParticle::update(float delta)
{
	Particle static_particle = Particle(
		Particle::get_position(),
		Vector3(0, 0, 0),
		Vector3(0, 0, 0),
		1
	);
	trail.push_back(static_particle);

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
