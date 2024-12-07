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
	DefaultParticle(const DefaultParticle& dp) : 
		particle(dp.particle), 
		sprite(dp.sprite), 
		collider(dp.collider.get_size(), &particle, nullptr){
		sprite.set_position(particle.get_position_ptr());
	}

	DefaultParticle& operator=(const DefaultParticle& dp) {
		particle = dp.particle;
		sprite = dp.sprite;
		sprite.set_position(particle.get_position_ptr());
		collider = SphereCollider(dp.collider.get_size(), &particle, nullptr);
		return *this;
	}

	DefaultParticle(const Particle& _particle, const Sphere& sphere) : 
		particle(_particle),
		sprite(sphere), 
		collider(sprite.get_size(), &particle, nullptr) {
		sprite.set_position(particle.get_position_ptr());
	}

	Particle* get_physical_particle() {
		return &particle;
	}

	void set_apply_gravity(bool new_value) {
		particle.set_apply_gravity(new_value);
	};
};