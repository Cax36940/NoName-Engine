#pragma once
#include "Mesh.h"

class CubeMesh : public Mesh {
public:
    CubeMesh() = default;
    CubeMesh(const CubeMesh&) = default;     
    CubeMesh& operator=(const CubeMesh&) = default;

	CubeMesh(Matrix4* transform) : Mesh(transform) {}

    const std::vector<Vector3>& get_vertices() const override { return CubeMesh::vertices; }
    const std::vector<unsigned int>& get_indices() const override { return CubeMesh::indices; }
	const Matrix3& get_moment_of_inertia() const override { return CubeMesh::moment_of_inertia; }

private:

    static const std::vector<Vector3> vertices;
    static const std::vector<unsigned int> indices;
	static const Matrix3 moment_of_inertia;
};

const std::vector<Vector3> CubeMesh::vertices =
	{	Vector3( 1,  1,  1),
		Vector3( 1, -1,  1),
		Vector3( 1, -1, -1),
		Vector3( 1,  1, -1),
		Vector3(-1,  1,  1),
		Vector3(-1,  1, -1),
		Vector3(-1, -1, -1),
		Vector3(-1, -1,  1)};

const std::vector<unsigned int> CubeMesh::indices = 
	{	0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		0, 7, 1,
		0, 4, 7,
		3, 6, 5,
		3, 2, 6,
		1, 6, 2,
		1, 7, 6,
		0, 3, 5,
		0, 5, 4};

const Matrix3 CubeMesh::moment_of_inertia = Matrix3(
	Vector3(2./3., 0, 0),
	Vector3(0, 2./3., 0),
	Vector3(0, 0, 2./3.)
);
