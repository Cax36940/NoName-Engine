#pragma once

#include "Component/Physics/DampedSimpleSpringComponent.hpp"
#include "Component/Graphics/Spring.hpp"

class DampedSimpleSpring {
public:
	DampedSimpleSpringComponent spring;
	Spring sprite;

	DampedSimpleSpring() = default;
	DampedSimpleSpring(const DampedSimpleSpring&) = default;
	DampedSimpleSpring& operator=(const DampedSimpleSpring&) = default;

	DampedSimpleSpring(const DampedSimpleSpringComponent& spring, const Spring& sprite) : spring(spring), sprite(sprite) {}

	DampedSimpleSpring(Particle* particle, const float stiffness, const float damping, const float default_length, const Vector3& fixed_point, const float width, const glm::vec3& color) : spring(particle, stiffness, damping, default_length, fixed_point), sprite(particle->get_position(), fixed_point, width, color) {}

	void update(const float& delta);
};