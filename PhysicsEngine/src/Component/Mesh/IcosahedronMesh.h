#pragma once
#include <vector>
#include "Mesh.h"
#include "Component/Vector3.hpp"
#define GOLDEN_RATIO 1.61803398875 

class IcosahedronMesh : public Mesh {
public:
	IcosahedronMesh() = default;
	IcosahedronMesh(const IcosahedronMesh&) = default;
	IcosahedronMesh& operator=(const IcosahedronMesh&) = default;

	IcosahedronMesh(Matrix4* transform) : Mesh(transform) {}

	const std::vector<Vector3>& get_vertices() const override { return IcosahedronMesh::vertices; }
	const std::vector<unsigned int>& get_indices() const override { return IcosahedronMesh::indices; }
	const Matrix3& get_moment_of_inertia() const override { return IcosahedronMesh::moment_of_inertia; }

private:

	static const std::vector<Vector3> vertices;
	static const std::vector<unsigned int> indices;
	static const Matrix3 moment_of_inertia;
};

const std::vector<Vector3> IcosahedronMesh::vertices = {
	Vector3(0, GOLDEN_RATIO, 1), 
	Vector3(0, GOLDEN_RATIO, -1), 
	Vector3(0, -GOLDEN_RATIO, -1),
	Vector3(0, -GOLDEN_RATIO, 1),			
	Vector3(-1, 0, GOLDEN_RATIO), 
	Vector3(-1, 0, -GOLDEN_RATIO), 
	Vector3(1, 0, -GOLDEN_RATIO), 
	Vector3(1, 0, GOLDEN_RATIO),	
	Vector3(-GOLDEN_RATIO, 1, 0), 
	Vector3(-GOLDEN_RATIO, -1, 0), 
	Vector3(GOLDEN_RATIO, -1, 0), 
	Vector3(GOLDEN_RATIO, 1, 0)}; 

const std::vector<unsigned int> IcosahedronMesh::indices =
{    0,  4,  7,
	 0,  7, 11,
	 0, 11,  1,
	 0,  1,  8,
	 0,  8,  4,

	 7,  4,  3,
	11,  7, 10,
	 1, 11,  6,
	 8,  1,  5,
	 4,  8,  9,
	
	 3, 10,  7,
	10,  6, 11,
	 6,  5,  1,
	 5,  9,  8,
	 9,  3,  4,
	
	10,  3,  2,
	 6, 10,  2,
	 5,  6,  2,
	 9,  5,  2,
	 3,  9,  2 };

const Matrix3 IcosahedronMesh::moment_of_inertia = Matrix3();
