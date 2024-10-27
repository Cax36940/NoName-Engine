#pragma once

#include "Component/Physics/CableComponent.hpp"
#include "Component/Graphics/Line.hpp"

class Cable {
public:
	CableComponent cable;
	Line sprite;

	Cable() = default;
	Cable(const Cable&) = default;
	Cable& operator=(const Cable&) = default;

	Cable(const CableComponent& cable, const Line& sprite) : cable(cable), sprite(sprite) {}

	Cable(Particle* particle1, Particle* particle2, const float default_length, const float width, const glm::vec3& color, const bool is_rigid = false) : cable(particle1, particle2, default_length, is_rigid), sprite(particle1->get_position_ptr(), particle2->get_position_ptr(), width, color) {}
};