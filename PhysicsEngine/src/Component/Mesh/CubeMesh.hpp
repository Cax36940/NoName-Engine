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

    const std::vector<Vector3>& get_vertices() const override { return vertices; }
    const std::vector<unsigned int>& get_indices() const override { return indices; }
	const Matrix3& get_moment_of_inertia() const override { return moment_of_inertia; }

private:
	CubeMesh(){

         std::vector<Vector3> tmp_vertices;
         std::vector<unsigned int> tmp_indices;
         tmp_vertices.reserve(2 * indices.size());
         tmp_indices.reserve(indices.size());
        

         for (size_t i = 0; i < indices.size(); i += 3) {
             // Get indices of the face
             unsigned int i0 = indices[i];
             unsigned int i1 = indices[i + 1];
             unsigned int i2 = indices[i + 2];

             // Get vertices of the face
             Vector3 v0 = vertices[i0];
             Vector3 v1 = vertices[i1];
             Vector3 v2 = vertices[i2];

             // Calculate the face normal
             Vector3 edge1 = v1 - v0;
             Vector3 edge2 = v2 - v0;
             Vector3 face_normal = Vector3::normalize(Vector3::cross(edge1, edge2));

             // Add vertices position followed by normal
             tmp_vertices.emplace_back(v0);
             tmp_vertices.emplace_back(face_normal);
             tmp_vertices.emplace_back(v1);
             tmp_vertices.emplace_back(face_normal);
             tmp_vertices.emplace_back(v2);
             tmp_vertices.emplace_back(face_normal);

             // Add indices to mesh
             tmp_indices.emplace_back(i);
             tmp_indices.emplace_back(i + 1);
             tmp_indices.emplace_back(i + 2);

         }

         vertex_buffer.emplace(tmp_vertices.data(), tmp_vertices.size() * sizeof(Vector3));
         index_buffer.emplace(tmp_indices.data(), tmp_indices.size());
         vertex_buffer_layout.Push<float>(3); // pos_x, pos_y, pos_z
         vertex_buffer_layout.Push<float>(3); // norm_x, norm_y, norm_z
         vertex_array.AddBuffer(vertex_buffer.value(), vertex_buffer_layout);

	}

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

};
