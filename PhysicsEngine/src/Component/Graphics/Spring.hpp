#pragma once

#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Vector3.hpp"
#include "Component/Matrix3.hpp"


class Spring : public GraphicsComponent
{
private:
	const Vector3* position_a;
	const Vector3* position_b;
	float radius = 10;
	glm::vec3 color;
	
public:
	Spring() = default;
	Spring(const Spring&) = default;
	Spring& operator=(const Spring&) = default;
	Spring(const Vector3* pos1, const Vector3* pos2, const float& radius, const glm::vec3& color) : position_a(pos1), position_b(pos2), radius(radius), color(color) {}
	
	void set_positions(const Vector3* pos_a, const Vector3* pos_b);
	void set_radius(const float& new_radius);
	void set_color(const float& r, const float& g, const float& b);

	void draw() override;
};

