#pragma once

#include "Component/Physics/DoubleSpringComponent.hpp"
#include "Component/Graphics/Spring.hpp"

class DoubleSpring {
public:
	DoubleSpringComponent spring;
	Spring sprite;

	DoubleSpring() = default;
	DoubleSpring(const DoubleSpring&) = default;
	DoubleSpring& operator=(const DoubleSpring&) = default;

	DoubleSpring(const DoubleSpringComponent& spring, const Spring& sprite) : spring(spring), sprite(sprite) {}

	DoubleSpring(Particle* particle1, Particle* particle2, const float stiffness, const float default_length, const float width, const glm::vec3& color) : spring(particle1, particle2, stiffness, default_length), sprite(particle1->get_position(), particle2->get_position(), width, color) {}

	void update(const float& delta);
};