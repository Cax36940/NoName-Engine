#pragma once
#include "Mesh.hpp"

class TetrahedronMesh : public Mesh {
public:
	TetrahedronMesh() = default;
	TetrahedronMesh(const TetrahedronMesh&) = default;
	TetrahedronMesh& operator=(const TetrahedronMesh&) = default;

	TetrahedronMesh(Matrix4* transform) : Mesh(transform) {}

	const std::vector<Vector3>& get_vertices() const override { return TetrahedronMesh::vertices; }
	const std::vector<unsigned int>& get_indices() const override { return TetrahedronMesh::indices; }
	const Matrix3& get_moment_of_inertia() const override { return TetrahedronMesh::moment_of_inertia; }

private:

	static const std::vector<Vector3> vertices;
	static const std::vector<unsigned int> indices;
	static const Matrix3 moment_of_inertia;
};

const std::vector<Vector3> TetrahedronMesh::vertices =
{	Vector3( 1,  1,  1), 
	Vector3( 1, -1, -1),
	Vector3(-1,  1, -1),
	Vector3(-1, -1,  1) };

const std::vector<unsigned int> TetrahedronMesh::indices =
{   0, 1, 2,
	0, 2, 3,
	0, 3, 1,
	1, 2, 3 };

const Matrix3 TetrahedronMesh::moment_of_inertia = Matrix3();