#pragma once
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

    virtual const VertexArray& get_vertex_array() const = 0;
    virtual const IndexBuffer& get_index_buffer() const = 0;

protected:
    MeshRessource() = default;
};
