#pragma once

#include "Component/Physics/SimpleSpringComponent.hpp"
#include "Component/Graphics/SpringSprite.hpp"

class SimpleSpring {
public:
	SimpleSpringComponent spring;
	SpringSprite sprite;

	SimpleSpring() = default;
	SimpleSpring(const SimpleSpring&) = default;
	SimpleSpring& operator=(const SimpleSpring&) = default;

	SimpleSpring(const SimpleSpringComponent& spring, const SpringSprite& sprite) : spring(spring), sprite(sprite) {}

	SimpleSpring(Particle* particle, const float stiffness, const float default_length, const Vector3& fixed_point, const float width, const glm::vec3& color) : spring(particle, stiffness, default_length, fixed_point), sprite(particle->get_position(), fixed_point, width, color) {}

	void SimpleSpring::update(const float& delta);
};