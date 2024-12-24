#pragma once

#include "Component/Physics/SpringComponent.hpp"
#include "Component/Graphics/SpringSprite.hpp"

class Spring {
public:
	SpringComponent spring;
	SpringSprite sprite;

	Spring() = default;
	Spring(const Spring&) = default;
	Spring& operator=(const Spring&) = default;

	Spring(const SpringComponent& spring, const SpringSprite& sprite) : spring(spring), sprite(sprite) {}

	Spring(Particle* particle1, Particle* particle2, const float stiffness, const float damping, const float default_length, const float width, const Vector3& color, const float rigid_coeff = -1.0f, const bool is_bungee = false) : spring(particle1, particle2, stiffness, damping, default_length, rigid_coeff, is_bungee), sprite(particle1->get_position_ptr(), particle2->get_position_ptr(), width, color) {}
};