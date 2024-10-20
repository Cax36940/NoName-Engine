#pragma once

#include "Component/Physics/DoubleCableComponent.hpp"
#include "Component/Graphics/Line.hpp"

class DoubleCable {
public:
	DoubleCableComponent cable;
	Line sprite;

	DoubleCable() = default;
	DoubleCable(const DoubleCable&) = default;
	DoubleCable& operator=(const DoubleCable&) = default;

	DoubleCable(const DoubleCableComponent& cable, const Line& sprite) : cable(cable), sprite(sprite) {}

	DoubleCable(Particle* particle1, Particle* particle2, const float default_length, const float width, const glm::vec3& color) : cable(particle1, particle2, default_length), sprite(particle1->get_position(), particle2->get_position(), width, color) {}

	void update(const float& delta);
};