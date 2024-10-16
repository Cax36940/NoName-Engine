#pragma once

#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Vector3.hpp"
#include "Component/Matrix3.h"


class Spring : public GraphicsComponent
{
private:
	Vector3 position_a;
	Vector3 position_b;
	float radius = 10;
	glm::vec3 color;
	
public:
	Spring() = default;
	Spring(const Vector3& pos, const float& size, const glm::vec3& color) : position(pos), size(size), color(color) {}

	void set_positions(const Vector3& pos_a, const Vector3& pos_b);
	void set_radius(const float& new_radius);
	void set_color(const float& r, const float& g, const float& b);

	void draw() override;
};

