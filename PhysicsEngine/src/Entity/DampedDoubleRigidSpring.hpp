#pragma once

#include "Component/Physics/DampedDoubleRigidSpringComponent.hpp"
#include "Component/Graphics/Spring.hpp"

class DampedDoubleRigidSpring {
public:
	DampedDoubleRigidSpringComponent spring;
	Spring sprite;

	DampedDoubleRigidSpring() = default;
	DampedDoubleRigidSpring(const DampedDoubleRigidSpring&) = default;
	DampedDoubleRigidSpring& operator=(const DampedDoubleRigidSpring&) = default;

	DampedDoubleRigidSpring(const DampedDoubleRigidSpringComponent& spring, const Spring& sprite) : spring(spring), sprite(sprite) {}

	DampedDoubleRigidSpring(Particle* particle1, Particle* particle2, const float stiffness, const float damping, const float default_length, const float width, const glm::vec3& color) : spring(particle1, particle2, stiffness, damping, default_length), sprite(particle1->get_position(), particle2->get_position(), width, color) {}

	void update(const float& delta);
};