#pragma once

#include "Vector3.hpp"

class Sphere
{
private:
	Vector3 position;
	float size;

public:
	Sphere() = default;
	Sphere(Vector3& pos, float size) : position(pos), size(size) {}

	void draw();
};