#pragma once
#include "MeshRessource.hpp"

class TetrahedronMesh : public MeshRessource {
public:
	TetrahedronMesh(const TetrahedronMesh&) = delete;
	TetrahedronMesh& operator=(const TetrahedronMesh&) = delete;

	static const TetrahedronMesh& get_instance() {
		static TetrahedronMesh cube_mesh;
		return cube_mesh;
	}

	const std::vector<Vector3>& get_vertices() const override { return vertices; }
	const std::vector<unsigned int>& get_indices() const override { return indices; }
	const Matrix3& get_moment_of_inertia() const override { return moment_of_inertia; }

private:
	TetrahedronMesh() {
		vertex_buffer.emplace(vertices.data(), vertices.size() * sizeof(Vector3));
		index_buffer.emplace(indices.data(), indices.size());
		vertex_buffer_layout.Push<float>(3); // pos_x, pos_y, pos_z
		vertex_array.AddBuffer(vertex_buffer.value(), vertex_buffer_layout);
	}

	const std::vector<Vector3> TetrahedronMesh::vertices {	
		Vector3( 1,  1,  1),
		Vector3( 1, -1, -1),
		Vector3(-1,  1, -1),
		Vector3(-1, -1,  1) };

	const std::vector<unsigned int> TetrahedronMesh::indices {   
		0, 1, 2,
		0, 2, 3,
		0, 3, 1,
		1, 2, 3 };

	const Matrix3 TetrahedronMesh::moment_of_inertia = Matrix3();
};