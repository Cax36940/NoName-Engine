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

    // Apply transform on vertices
    std::vector<Vector3> vertices = get_vertices();
    for (auto& vertex : vertices) {
        vertex = transform_matrix * vertex;
    }

    const std::vector<unsigned int> indices = get_indices();

    for (size_t i = 0; i < indices.size(); i += 3) {
        // Get indices of the face
        unsigned int i0 = indices[i];
        unsigned int i1 = indices[i + 1];
        unsigned int i2 = indices[i + 2];

        // Get vertices of the face
        ofDefaultVertexType v0 = Vector3::to_glm_vec3(vertices[i0]);
        ofDefaultVertexType v1 = Vector3::to_glm_vec3(vertices[i1]);
        ofDefaultVertexType v2 = Vector3::to_glm_vec3(vertices[i2]);

        // Add vertices to mesh
        mesh.addVertex(v0);
        mesh.addVertex(v1);
        mesh.addVertex(v2);

        // Add indices to mesh
        mesh.addIndex(i);
        mesh.addIndex(i + 1);
        mesh.addIndex(i + 2);

        // Calculate the face normal
        ofDefaultVertexType edge1 = v1 - v0;
        ofDefaultVertexType edge2 = v2 - v0;
        ofDefaultVertexType face_normal = glm::normalize(glm::cross(edge1,edge2));

        // Add normals to mesh
        mesh.addNormal(face_normal);
        mesh.addNormal(face_normal);
        mesh.addNormal(face_normal);

    }

    mesh.draw();
    
}
