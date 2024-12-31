#pragma once
#include "MeshRessource.hpp"
#include "Quaternion.hpp"

#define ARROW_LENGTH 5.0f

class ArrowMesh : public MeshRessource
{
public:
	ArrowMesh(const ArrowMesh&) = delete;
	ArrowMesh& operator=(const ArrowMesh& mesh) = delete;

	static const ArrowMesh& get_instance() {
		static ArrowMesh arrow_mesh;
		return arrow_mesh;
	}

	const std::vector<Vector3>& get_vertices() const override { return vertices; }
	const std::vector<unsigned int>& get_indices() const override { return indices; }
	const Matrix3& get_moment_of_inertia() const override { return moment_of_inertia; }

private:
	ArrowMesh() {
		vertex_buffer.emplace(vertices.data(), vertices.size() * sizeof(Vector3));
		index_buffer.emplace(indices.data(), indices.size());
		vertex_buffer_layout.Push<float>(3); // pos_x, pos_y, pos_z
		vertex_array.AddBuffer(vertex_buffer.value(), vertex_buffer_layout);
	}

	const std::vector<Vector3> vertices = {
		Vector3(0.2, ARROW_LENGTH, -0.2),
		Vector3(0.2, 0, -0.2),
		Vector3(0.2, ARROW_LENGTH, 0.2),
		Vector3(0.2, 0, 0.2),

		Vector3(-0.2, ARROW_LENGTH, -0.2),
		Vector3(-0.2, 0, -0.2),
		Vector3(-0.2, ARROW_LENGTH,  0.2),
		Vector3(-0.2, 0,  0.2),

		Vector3(0.48, ARROW_LENGTH, 0.48),
		Vector3(-0.48, ARROW_LENGTH, 0.48),
		Vector3(0.48, ARROW_LENGTH,  -0.48),
		Vector3(-0.48, ARROW_LENGTH,  -0.48),

		Vector3(0.0, ARROW_LENGTH + 1.5, 0.0)
	};

	const std::vector<unsigned int> indices {
		0, 11, 10,
		2, 7, 3,
		6, 5, 7,
		1, 7, 5,

		0, 3, 1,
		4, 1, 5,
		11, 9, 12,
		6, 8, 9,

		4, 9, 11,
		2, 10, 8,
		9, 8, 12,
		10, 11, 12,

		8, 10, 12,
		0, 4, 11,
		2, 6, 7,
		6, 4, 5,

		1, 3, 7,
		0, 2, 3,
		4, 0, 1,
		6, 2, 8,

		4, 6, 9,
		2, 0, 10
	};

	const Matrix3 moment_of_inertia = Matrix3();
};