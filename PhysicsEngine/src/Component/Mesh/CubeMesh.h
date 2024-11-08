#pragma once
#include "Mesh.h"

class CubeMesh : public Mesh {
public:
    CubeMesh() = default;
    CubeMesh(const CubeMesh&) = default;     
    CubeMesh& operator=(const CubeMesh&) = default;

	CubeMesh(CubeMesh&& cube_mesh) noexcept : Mesh(std::move(cube_mesh.transform)) { cube_mesh.transform = nullptr; };
	CubeMesh& operator=(CubeMesh&& cube_mesh) noexcept { 
		transform = cube_mesh.transform; 
		cube_mesh.transform = nullptr;
		return *this; };
	CubeMesh(Matrix3* transform) : Mesh(transform) {}

    const std::vector<Vector3>& get_vertices() const override { return CubeMesh::vertices; }
    const std::vector<unsigned int>& get_indices() const override { return CubeMesh::indices; }

	void set_transform_ptr(Matrix3* new_transform) {
		transform = new_transform;
	}

private:

    static const std::vector<Vector3> vertices;
    static const std::vector<unsigned int> indices;
};

const std::vector<Vector3> CubeMesh::vertices =
	{	Vector3( 1,  1,  1),
		Vector3( 1,  1, -1),
		Vector3( 1, -1, -1),
		Vector3( 1, -1,  1),
		Vector3(-1,  1,  1),
		Vector3(-1,  1, -1),
		Vector3(-1, -1, -1),
		Vector3(-1, -1,  1)};

const std::vector<unsigned int> CubeMesh::indices = 
	{	0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		0, 3, 7,
		0, 7, 4,
		1, 5, 6,
		1, 6, 2,
		3, 2, 6,
		3, 6, 7,
		0, 1, 5,
		0, 5, 4};

