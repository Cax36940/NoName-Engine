#include "Particle.hpp"
#include <of3dGraphics.h>

Particle::Particle(Vector3& pos, Vector3& vel, Vector3& acc, float weight)
	: position(pos)
	, velocity(vel)
	, acceleration(acc)
	, weight(weight)
{
	this->size = 5;
}

Vector3 Particle::get_position() const
{
	return position;
}

void Particle::set_size(float s)
{
	this->size = s;
}

void Particle::update(float delta)
{
	velocity = velocity + acceleration * delta;
	position = position + velocity * delta + 0.5 * acceleration * delta * delta;
}

void Particle::draw()
{
	glm::vec3 pos = glm::vec3(position.x, position.y, position.z);
	ofDrawSphere(pos, this->size);
}

void Particle::drawSingleParticle()
{
	glm::vec3 pos = glm::vec3(800, 50, 0);
	ofDrawSphere(pos, this->size);
}