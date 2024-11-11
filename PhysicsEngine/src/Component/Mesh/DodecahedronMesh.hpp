#pragma once
#include "Mesh.hpp"
#define GOLDEN_RATIO 1.61803398875 

class DodecahedronMesh : public Mesh {
public:
	DodecahedronMesh() = default;
	DodecahedronMesh(const DodecahedronMesh&) = default;
	DodecahedronMesh& operator=(const DodecahedronMesh&) = default;

	DodecahedronMesh(Matrix4* transform) : Mesh(transform) {}

	const std::vector<Vector3>& get_vertices() const override { return DodecahedronMesh::vertices; }
	const std::vector<unsigned int>& get_indices() const override { return DodecahedronMesh::indices; }
	const Matrix3& get_moment_of_inertia() const override { return DodecahedronMesh::moment_of_inertia; }

private:

	static const std::vector<Vector3> vertices;
	static const std::vector<unsigned int> indices;
	static const Matrix3 moment_of_inertia;
};

const std::vector<Vector3> DodecahedronMesh::vertices = {
	Vector3(1, 1, 1), 
	Vector3(1, 1, -1), 
	Vector3(1, -1, -1), 
	Vector3(1, -1, 1),
									
	Vector3(-1, 1, 1), 
	Vector3(-1, 1, -1), 
	Vector3(-1, -1, -1), 
	Vector3(-1, -1, 1),
									
	Vector3(0, GOLDEN_RATIO, 1 / GOLDEN_RATIO), 
	Vector3(0, GOLDEN_RATIO, -1 / GOLDEN_RATIO), 
	Vector3(0, -GOLDEN_RATIO, -1 / GOLDEN_RATIO), 
	Vector3(0, -GOLDEN_RATIO, 1 / GOLDEN_RATIO),

	Vector3(-1 / GOLDEN_RATIO, 0, GOLDEN_RATIO),
	Vector3(-1 / GOLDEN_RATIO, 0, -GOLDEN_RATIO),
	Vector3(1 / GOLDEN_RATIO, 0, -GOLDEN_RATIO),
	Vector3(1 / GOLDEN_RATIO, 0, GOLDEN_RATIO),

	Vector3(GOLDEN_RATIO,  -1 / GOLDEN_RATIO, 0),
	Vector3(-GOLDEN_RATIO,  -1 / GOLDEN_RATIO, 0),
	Vector3(-GOLDEN_RATIO, 1 / GOLDEN_RATIO, 0),
	Vector3(GOLDEN_RATIO, 1 / GOLDEN_RATIO, 0)};

const std::vector<unsigned int> DodecahedronMesh::indices =
{     9, 18,  8,
	  9,  5, 18,
	 18,  4,  8,
	  9,  8, 19,
	  9, 19,  1,
	  8,  0, 19,

	 10, 11, 17,
	 10, 17,  6,
	 11,  7, 17,
	 11, 10, 16,
	 10,  2, 16,
	 11, 16,  3,

	 17, 18, 13,
	 17, 13,  6,
	 18,  5, 13,
	 18, 17, 12,
	 18, 12,  4,
	 17,  7, 12,

	 16, 19, 15,
	 16, 15,  3,
	 19,  0, 15,
	 19, 16, 14,
	 19, 14,  1, 
	 16,  2, 14, 

	 14, 13,  9,
	 13,  5,  9,
	 14,  9,  1,
	 13, 14, 10,
	 13, 10,  6,
	 14,  2, 10,

	 12, 15,  8,
	 12,  8,  4,
	 15,  0,  8,
	 15, 12, 11,
	 15, 11,  3,
	 12,  7,  11 };

const Matrix3 DodecahedronMesh::moment_of_inertia = Matrix3();