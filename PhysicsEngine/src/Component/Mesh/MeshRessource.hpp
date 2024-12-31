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

protected:
    MeshRessource() = default;

    std::optional<VertexBuffer> vertex_buffer; // std::optional used to differ initialisation because it needs  of the child class
    VertexBufferLayout vertex_buffer_layout;
    VertexArray vertex_array;
    std::optional<IndexBuffer> index_buffer;
};
