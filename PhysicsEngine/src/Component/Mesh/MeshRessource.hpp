#pragma once
#include <optional>

#include "Matrix3.hpp"
#include "Vector3.hpp"

#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "IndexBuffer.hpp"

class MeshRessource {
public:
    virtual const std::vector<Vector3>& get_vertices() const = 0;
    virtual const std::vector<unsigned int>& get_indices() const = 0;
    virtual const Matrix3& get_moment_of_inertia() const = 0;

    const VertexArray& get_vertex_array() const { return vertex_array; }
    const IndexBuffer& get_index_buffer() const { return index_buffer.value(); }

    void init_ressource() {

        const std::vector<Vector3>& vertices = get_vertices();
        const std::vector<unsigned int>& indices = get_indices();

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
    };

protected:
    MeshRessource() = default;

    std::optional<VertexBuffer> vertex_buffer; // std::optional used to differ initialisation because it needs  of the child class
    VertexBufferLayout vertex_buffer_layout;
    VertexArray vertex_array;
    std::optional<IndexBuffer> index_buffer;
};
