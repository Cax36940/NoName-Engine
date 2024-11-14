#pragma once
#include "Component/Mesh/ArrowMesh.hpp"

class Origin {
public:
	Origin() = default;
	Origin(const Origin&) = default;
	Origin& operator=(const Origin& mesh) = default;

	Origin(float length, float size) : length(length), size(size) {
		xAxis = ArrowMesh(length, size * Matrix3());
		xAxis.set_origin_and_direction(Vector3(), Quaternion(0.707, 0, 0, -0.707));
		yAxis = ArrowMesh(length, size * Matrix3());
		zAxis = ArrowMesh(length, size * Matrix3());
		zAxis.set_origin_and_direction(Vector3(), Quaternion(0.707, 0.707, 0, 0));
	}

private:
	float length;
	float size;
	ArrowMesh xAxis;
	ArrowMesh yAxis;
	ArrowMesh zAxis;
};