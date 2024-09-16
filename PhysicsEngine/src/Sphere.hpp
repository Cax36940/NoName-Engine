#pragma once

#include "Vector3.hpp"

class Sphere
{
private:
	Vector3 position;
	float size;
	glm::vec3 color;

public:
	Sphere() = default;
	Sphere(const Vector3& pos, float size, const glm::vec3& color) : position(pos), size(size), color(color) {}

	void set_position(const Vector3& pos);
	void set_size(float new_size);
	void set_color(float r, float g, float b);

	void draw();
};