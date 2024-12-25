#pragma once

#include "Component/Graphics/GraphicsComponent.hpp"
#include "Vector3.hpp"

class Line : public GraphicsComponent
{
private:
	const Vector3* position_a;
	const Vector3* position_b;
	float width;
	Vector3 color;

public:
	Line() = default;
	Line(const Line&) = default;
	Line& operator=(const Line&) = default;

	Line(const Vector3* pos1, const Vector3* pos2, const float& width, const Vector3& color) : position_a(pos1), position_b(pos2), width(width), color(color) {}

	void set_positions_ptr(const Vector3* pos1, const Vector3* pos2);
	void set_width(const float& new_width);
	void set_color(const float& r, const float& g, const float& b);

	void draw() override;
};