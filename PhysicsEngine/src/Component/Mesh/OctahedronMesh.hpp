#pragma once
#include "MeshRessource.hpp"

class OctahedronMesh : public MeshRessource {
public:
	OctahedronMesh(const OctahedronMesh&) = delete;
	OctahedronMesh& operator=(const OctahedronMesh&) = delete;

	static const OctahedronMesh& get_instance() {
		static OctahedronMesh octahedron_mesh;
		return octahedron_mesh;
	}

	const std::vector<Vector3>& get_vertices() const override { return vertices; }
	const std::vector<unsigned int>& get_indices() const override { return indices; }
	const Matrix3& get_moment_of_inertia() const override { return moment_of_inertia; }

private:
	OctahedronMesh() {
		vertex_buffer.emplace(vertices.data(), vertices.size() * sizeof(Vector3));
		index_buffer.emplace(indices.data(), indices.size());
		vertex_buffer_layout.Push<float>(3); // pos_x, pos_y, pos_z
		vertex_array.AddBuffer(vertex_buffer.value(), vertex_buffer_layout);
	}

	const std::vector<Vector3> OctahedronMesh::vertices {
		Vector3(1, 0, 0),
		Vector3(0, 1, 0),
		Vector3(0, 0, 1),
		Vector3(-1, 0, 0),
		Vector3(0, -1, 0),
		Vector3(0, 0, -1)
	};

	const std::vector<unsigned int> OctahedronMesh::indices {   
		0, 1, 2,
		0, 2, 4,
		4, 2, 3,
		1, 3, 2,
		0, 4, 5,
		4, 3, 5,
		3, 1, 5,
		1, 0, 5
	};

	const Matrix3 OctahedronMesh::moment_of_inertia = Matrix3();

};
