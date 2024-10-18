#pragma once

#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Vector3.hpp"

class SpringSprite : public GraphicsComponent
{
private:
	Vector3 position_a;
	Vector3 position_b;
	float width;
	glm::vec3 color;

public:
	SpringSprite() = default;
	SpringSprite(const SpringSprite&) = default;
	SpringSprite& operator=(const SpringSprite&) = default;

	SpringSprite(const Vector3& pos1, const Vector3& pos2, const float& width, const glm::vec3& color) : position_a(pos1), position_b(pos2), width(width), color(color) {}

	void set_width(const float& new_width);
	void set_color(const float& r, const float& g, const float& b);
	void set_positions(const Vector3& pos1, const Vector3& pos2);

	void draw() override;
};