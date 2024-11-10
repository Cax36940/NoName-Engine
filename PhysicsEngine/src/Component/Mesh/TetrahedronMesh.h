#pragma once
#include "Mesh.h"

class TetrahedronMesh : public Mesh {
public:
	TetrahedronMesh() = default;
	TetrahedronMesh(const TetrahedronMesh&) = default;
	TetrahedronMesh& operator=(const TetrahedronMesh&) = default;

	TetrahedronMesh(Matrix3* transform) : Mesh(transform) {}

	const std::vector<Vector3>& get_vertices() const override { return TetrahedronMesh::vertices; }
	const std::vector<unsigned int>& get_indices() const override { return TetrahedronMesh::indices; }

private:

	static const std::vector<Vector3> vertices;
	static const std::vector<unsigned int> indices;
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

