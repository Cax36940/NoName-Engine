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

    const std::vector<Vector3> vertices = get_vertices();

    for (const auto& vertex : vertices) {
        mesh.addVertex(Vector3::to_glm_vec3(transform_matrix * vertex));
        mesh.addColor(ofColor(255, 0, 0));
    }

    const std::vector<unsigned int> indices = get_indices();

    for (const auto& index : indices) {
        mesh.addIndex(index);
    }

    mesh.addNormals(mesh.getFaceNormals());
    mesh.draw();
}
