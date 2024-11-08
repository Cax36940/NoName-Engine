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

    for (const auto& vertex : get_vertices()) {
        mesh.addVertex(Vector3::to_glm_vec3(vertex));
        mesh.addColor(ofFloatColor(255, 255, 255));
    }

    for (const auto& index : get_indices()) {
        mesh.addIndex(index);
    }

    mesh.draw();
}
