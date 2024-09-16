#pragma once

#include "Particle.hpp"
#include "Sphere.hpp"

class DefaultParticle {
public:
	Particle particle;
	Sphere sprite;

	DefaultParticle() = default;

	DefaultParticle(const Particle& particle, const Sphere& sphere) : particle(particle), sprite(sphere) {}

	virtual void draw();

	void update(float delta);
};