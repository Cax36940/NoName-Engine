#pragma once
#include "Component/Mesh/ArrowMesh.hpp"

class Origin {
public:
	Origin() = default;
	Origin(const Origin&) = default;
	Origin& operator=(const Origin& mesh)
	{
		length = mesh.length;
		size = mesh.size;
		xAxis = mesh.xAxis;
		yAxis = mesh.yAxis;
		zAxis = mesh.zAxis;
		return *this;
	};

	Origin(float length, float size) : length(length), size(size) {
		xAxis = ArrowMesh(length, size * Matrix3());
		xAxis.set_origin_and_direction(Vector3(), Quaternion(0.707, 0, 0, -0.707));
		xAxis.set_color(Vector3(255, 0, 0));

		yAxis = ArrowMesh(length, size * Matrix3());
		yAxis.set_color(Vector3(0, 0, 255));

		zAxis = ArrowMesh(length, size * Matrix3());
		zAxis.set_origin_and_direction(Vector3(), Quaternion(0.707, 0.707, 0, 0));
		zAxis.set_color(Vector3(0, 255, 0));
	}

private:
	float length;
	float size;
	ArrowMesh xAxis;
	ArrowMesh yAxis;
	ArrowMesh zAxis;
};