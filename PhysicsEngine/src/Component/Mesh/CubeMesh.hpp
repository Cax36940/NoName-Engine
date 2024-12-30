#pragma once
#include "MeshRessource.hpp"

class CubeMesh : public MeshRessource {
public:
    CubeMesh(const CubeMesh&) = delete;     
    CubeMesh& operator=(const CubeMesh&) = delete;

	static const CubeMesh& get_instance() {
		static CubeMesh cube_mesh;
		return cube_mesh;
	}

    const std::vector<Vector3>& get_vertices() const override { return get_instance().vertices; }
    const std::vector<unsigned int>& get_indices() const override { return get_instance().indices; }
	const Matrix3& get_moment_of_inertia() const override { return get_instance().moment_of_inertia; }

	const VertexArray& get_vertex_array() const { return vertex_array; }
	const IndexBuffer& get_index_buffer() const { return index_buffer; }

private:
	CubeMesh() : 
		vertex_buffer(&vertices[0], vertices.size() * sizeof(Vector3)),
		index_buffer(&indices[0], indices.size()) 
	{
		vertex_buffer_layout.Push<float>(3); // pos_x, pos_y, pos_z
		vertex_array.AddBuffer(vertex_buffer, vertex_buffer_layout);
	};

    const std::vector<Vector3> vertices{ 
		Vector3(1,  1,  1),
		Vector3(1, -1,  1),
		Vector3(1, -1, -1),
		Vector3(1,  1, -1),
		Vector3(-1,  1,  1),
		Vector3(-1,  1, -1),
		Vector3(-1, -1, -1),
		Vector3(-1, -1,  1) };

    const std::vector<unsigned int> indices{ 
		0, 1, 2,
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
		0, 5, 4 };

	const Matrix3 moment_of_inertia = Matrix3(
		Vector3(2. / 3., 0, 0),
		Vector3(0, 2. / 3., 0),
		Vector3(0, 0, 2. / 3.)
	);

	VertexBuffer vertex_buffer;
	VertexBufferLayout vertex_buffer_layout;
	VertexArray vertex_array;
	IndexBuffer index_buffer;
};


