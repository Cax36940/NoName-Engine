#pragma once
#include "Entity/Arrow.hpp"

class Origin {
public:
	Origin() = default;
	Origin(const Origin&) = default;
	Origin& operator=(const Origin& mesh) = default;

	Origin(float size) :
	xAxis(Vector3(0, 0, 0), size, Vector3(255, 0, 0), Quaternion(0.707, 0, 0, -0.707)),
	yAxis(Vector3(0, 0, 0), size, Vector3(0, 255, 0), Quaternion(1, 0, 0, 0)),
	zAxis(Vector3(0, 0, 0), size, Vector3(0, 0, 255), Quaternion(0.707, 0.707, 0, 0)) {}

private:
	Arrow xAxis;
	Arrow yAxis;
	Arrow zAxis;
};