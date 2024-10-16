#pragma once

#include "Component/Particle.hpp"
#include "Component/Graphics/Sphere.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"

class DefaultParticle {
public:
	Particle particle;
	Sphere sprite;
	SphereCollider collider;

	DefaultParticle() = default;
	DefaultParticle(const DefaultParticle&) = default;
	DefaultParticle& operator=(const DefaultParticle&) = default;

	DefaultParticle(const Particle& particle, const Sphere& sphere);

	void update(const float& delta);

	Particle* get_physical_particle() {
		return &particle;
	}
};