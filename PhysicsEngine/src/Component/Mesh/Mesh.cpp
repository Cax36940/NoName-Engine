#include <ofMaterial.h>
#include <ofMesh.h>
#include "Mesh.h"

Mesh::Mesh() : transform(nullptr) {}

Mesh::Mesh(const Mesh& mesh) : transform(nullptr) {}

Mesh& Mesh::operator=(const Mesh& mesh) {
    transform = nullptr;
    return *this;
}

Mesh::Mesh(Matrix3* transform) : transform(transform) {}

void Mesh::draw()
{
    ofMesh mesh;
    Matrix3 transform_matrix;

    if (transform == nullptr) {
        std::cout << "[WARNING] Mesh transform is nullptr. Mesh at address : " << this << std::endl;
    }
    else {
        transform_matrix = *transform;
    }

    // Add vertices of the mesh
    const std::vector<Vector3> vertices = get_vertices();
    for (const auto& vertex : vertices) {
        mesh.addVertex(Vector3::to_glm_vec3(transform_matrix * vertex));
        mesh.addColor(ofColor(255, 0, 0));
    }

    // Add indices of the mesh
    const std::vector<unsigned int> indices = get_indices();
    for (const auto& index : indices) {
        mesh.addIndex(index);
    }

    // Calculate normals per vertex by accumulating face normals
    std::vector<ofDefaultNormalType> vertex_normals(vertices.size());

    for (size_t i = 0; i < indices.size(); i += 3) {
        unsigned int i0 = indices[i];
        unsigned int i1 = indices[i + 1];
        unsigned int i2 = indices[i + 2];

        // Get vertices of the face
        ofDefaultVertexType v0 = mesh.getVertex(i0);
        ofDefaultVertexType v1 = mesh.getVertex(i1);
        ofDefaultVertexType v2 = mesh.getVertex(i2);

        // Calculate the face normal
        ofDefaultVertexType edge1 = v1 - v0;
        ofDefaultVertexType edge2 = v2 - v0;
        ofDefaultVertexType face_normal = glm::normalize(glm::cross(edge1,edge2));

        // Accumulate face normal for each vertex
        vertex_normals[i0] += face_normal;
        vertex_normals[i1] += face_normal;
        vertex_normals[i2] += face_normal;
    }

    // Normalize accumulated normals and add them to the mesh
    mesh.addNormals(vertex_normals);

    mesh.draw();
    
}
