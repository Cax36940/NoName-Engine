#pragma once

#include "Component/Particle.hpp"
#include "Component/Graphics/Sphere.hpp"

class DefaultParticle {
public:
	Particle particle;
	Sphere sprite;

	DefaultParticle() = default;

	DefaultParticle(const Particle& particle, const Sphere& sphere) : particle(particle), sprite(sphere) {}

	void update(const float& delta);
};