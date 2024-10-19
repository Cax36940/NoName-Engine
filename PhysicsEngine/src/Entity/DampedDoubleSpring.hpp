#pragma once

#include "Component/Physics/DampedDoubleSpringComponent.hpp"
#include "Component/Graphics/Spring.hpp"

class DampedDoubleSpring {
public:
	DampedDoubleSpringComponent spring;
	Spring sprite;

	DampedDoubleSpring() = default;
	DampedDoubleSpring(const DampedDoubleSpring&) = default;
	DampedDoubleSpring& operator=(const DampedDoubleSpring&) = default;

	DampedDoubleSpring(const DampedDoubleSpringComponent& spring, const Spring& sprite) : spring(spring), sprite(sprite) {}

	DampedDoubleSpring(Particle* particle1, Particle* particle2, const float stiffness, const float damping, const float default_length, const float width, const glm::vec3& color) : spring(particle1, particle2, stiffness, damping, default_length), sprite(particle1->get_position(), particle2->get_position(), width, color) {}

	void update(const float& delta);
};