#pragma once

#include "Component/Physics/DoubleRodComponent.hpp"
#include "Component/Graphics/Line.hpp"

class DoubleRod {
public:
	DoubleRodComponent rod;
	Line sprite;

	DoubleRod() = default;
	DoubleRod(const DoubleRod&) = default;
	DoubleRod& operator=(const DoubleRod&) = default;

	DoubleRod(const DoubleRodComponent& rod, const Line& sprite) : rod(rod), sprite(sprite) {}

	DoubleRod(Particle* particle1, Particle* particle2, const float default_length, const float width, const glm::vec3& color) : rod(particle1, particle2, default_length), sprite(particle1->get_position_ptr(), particle2->get_position_ptr(), width, color) {}
};