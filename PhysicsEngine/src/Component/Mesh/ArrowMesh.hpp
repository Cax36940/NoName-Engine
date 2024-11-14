#pragma once
#include "Mesh.hpp"
#include "Component/Quaternion.hpp"

class ArrowMesh : public Mesh
{
public:
    ArrowMesh() = default;
    ArrowMesh(const ArrowMesh&) = default;
	ArrowMesh& operator=(const ArrowMesh& mesh) {
		tf = mesh.tf;
		length = mesh.length;
		sized_vertices = {
			Vector3(0.2, length, -0.2),
			Vector3(0.2, 0, -0.2),
			Vector3(0.2, length, 0.2),
			Vector3(0.2, 0, 0.2),

			Vector3(-0.2, length, -0.2),
			Vector3(-0.2, 0, -0.2),
			Vector3(-0.2, length,  0.2),
			Vector3(-0.2, 0,  0.2),

			Vector3(0.48, length, 0.48),
			Vector3(-0.48, length, 0.48),
			Vector3(0.48, length,  -0.48),
			Vector3(-0.48, length,  -0.48),

			Vector3(0.0, length + 1.5, 0.0)
		};
		set_transform_ptr(&tf);
		return *this;
	};

    ArrowMesh(float _length, Matrix4 transform) : Mesh(&tf), tf(transform), length(_length) {}

	void set_origin_and_direction(Vector3 origin, Quaternion dir) {
		Matrix3 rotatedMatrix = Quaternion::toMatrix3(dir);
		tf = Matrix4(rotatedMatrix) * tf;
		tf.set_translate(origin);
	}

    const std::vector<Vector3>& get_vertices() const override { return sized_vertices; }
    const std::vector<unsigned int>& get_indices() const override { return ArrowMesh::indices; }
    const Matrix3& get_moment_of_inertia() const override { return ArrowMesh::moment_of_inertia; }

private:

	Matrix4 tf = Matrix4(15*Matrix3(), Vector3(1, 1, 1));
	float length;
	std::vector<Vector3> sized_vertices = {
		Vector3(0.2, length, -0.2),
		Vector3(0.2, 0, -0.2),
		Vector3(0.2, length, 0.2),
		Vector3(0.2, 0, 0.2),

		Vector3(-0.2, length, -0.2),
		Vector3(-0.2, 0, -0.2),
		Vector3(-0.2, length,  0.2),
		Vector3(-0.2, 0,  0.2),

		Vector3(0.48, length, 0.48),
		Vector3(-0.48, length, 0.48),
		Vector3(0.48, length,  -0.48),
		Vector3(-0.48, length,  -0.48),

		Vector3(0.0, length + 1.5, 0.0)
	};
    static const std::vector<Vector3> vertices;
    static const std::vector<unsigned int> indices;
    static const Matrix3 moment_of_inertia;
};

const std::vector<Vector3> ArrowMesh::vertices =
{ 
	Vector3(0.2, 1, -0.2),
	Vector3(0.2, 0, -0.2),
	Vector3(0.2, 1, 0.2),
	Vector3(0.2, 0, 0.2),

	Vector3(-0.2, 1, -0.2),
	Vector3(-0.2, 0, -0.2),
	Vector3(-0.2, 1,  0.2),
	Vector3(-0.2, 0,  0.2),

	Vector3(0.48, 1, 0.48),
	Vector3(-0.48, 1, 0.48),
	Vector3(0.48, 1,  -0.48),
	Vector3(-0.48, 1,  -0.48),

	Vector3(0.0, 1.75, 0.0)
};

const std::vector<unsigned int> ArrowMesh::indices =
{ 
	0, 11, 10,
	2, 7, 3,
	6, 5, 7,
	1, 7, 5,

	0, 3, 1,
	4, 1, 5,
	11, 9, 12,
	6, 8, 9,

	4, 9, 11,
	2, 10, 8,
	9, 8, 12,
	10, 11, 12,

	8, 10, 12,
	0, 4, 11,
	2, 6, 7,
	6, 4, 5,

	1, 3, 7,
	0, 2, 3,
	4, 0, 1,
	6, 2, 8,

	4, 6, 9,
	2, 0, 10
};

const Matrix3 ArrowMesh::moment_of_inertia = Matrix3(
	Vector3(0, 0, 0),
	Vector3(0, 0, 0),
	Vector3(0, 0, 0)
);
