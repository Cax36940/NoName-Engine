#pragma once

#include "Component/Physics/DoubleRigidSpringComponent.hpp"
#include "Component/Graphics/Spring.hpp"

class DoubleRigidSpring {
public:
	DoubleRigidSpringComponent spring;
	Spring sprite;

	DoubleRigidSpring() = default;
	DoubleRigidSpring(const DoubleRigidSpring&) = default;
	DoubleRigidSpring& operator=(const DoubleRigidSpring&) = default;

	DoubleRigidSpring(const DoubleRigidSpringComponent& spring, const Spring& sprite) : spring(spring), sprite(sprite) {}

	DoubleRigidSpring(Particle* particle1, Particle* particle2, const float stiffness, const float default_length, const float width, const glm::vec3& color) : spring(particle1, particle2, stiffness, default_length), sprite(particle1->get_position(), particle2->get_position(), width, color) {}

	void update(const float& delta);
};