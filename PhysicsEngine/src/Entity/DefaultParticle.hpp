#pragma once

#include "Component/Particle.hpp"
#include "Component/Graphics/Sphere.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"

class DefaultParticle : public UpdatesComponent{
public:
	Particle particle;
	Sphere sprite;
	SphereCollider collider;

	DefaultParticle() = default;
	DefaultParticle(const DefaultParticle& dp) : 
		particle(dp.particle), 
		sprite(dp.sprite), 
		collider(dp.collider.get_size(), &particle){}
	DefaultParticle& operator=(const DefaultParticle& dp) {
		particle = dp.particle;
		sprite = dp.sprite;
		collider = SphereCollider(dp.collider.get_size(), &particle);
		return *this;
	}

	DefaultParticle(const Particle& _particle, const Sphere& sphere);

	void update(float delta) override;

	Particle* get_physical_particle() {
		return &particle;
	}
};