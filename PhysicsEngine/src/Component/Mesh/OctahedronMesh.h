#pragma once
#include <vector>
#include "Mesh.h"
#include "Component/Vector3.hpp"
class OctahedronMesh : public Mesh {
public:
	OctahedronMesh() = default;
	OctahedronMesh(const OctahedronMesh&) = default;
	OctahedronMesh& operator=(const OctahedronMesh&) = default;

	OctahedronMesh(Matrix3* transform) : Mesh(transform) {}

	const std::vector<Vector3>& get_vertices() const override { return OctahedronMesh::vertices; }
	const std::vector<unsigned int>& get_indices() const override { return OctahedronMesh::indices; }

private:

	static const std::vector<Vector3> vertices;
	static const std::vector<unsigned int> indices;
};

const std::vector<Vector3> OctahedronMesh::vertices = {
	Vector3(1, 0, 0), 
	Vector3(0, 1, 0), 
	Vector3(0, 0, 1),
	Vector3(-1, 0, 0), 
	Vector3(0, -1, 0), 
	Vector3(0, 0, -1)
};

const std::vector<unsigned int> OctahedronMesh::indices =
{ 0, 1, 2,
	0, 2, 4,
	4, 2, 3,
	1, 3, 2,
	0, 4, 5,
	4, 3, 5,
	3, 1, 5,
	1, 0, 5
	 };


