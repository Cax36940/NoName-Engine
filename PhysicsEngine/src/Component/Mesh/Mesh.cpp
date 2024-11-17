#include <ofMaterial.h>
#include <ofMesh.h>
#include <ofGraphics.h>
#include <of3dGraphics.h>
#include "Mesh.hpp"

Mesh::Mesh() : mesh_ressource(nullptr), transform(nullptr), color(255, 0, 0) {}

Mesh::Mesh(const Mesh& mesh) : mesh_ressource(mesh.mesh_ressource), transform(nullptr), color(mesh.color) {}

Mesh& Mesh::operator=(const Mesh& mesh) {
    mesh_ressource = mesh.mesh_ressource;
    transform = nullptr;
    color = mesh.color;
    return *this;
}

Mesh::Mesh(const MeshRessource* mesh_ressource, const Vector3& color, Matrix4* transform) : mesh_ressource(mesh_ressource), transform(transform), color(color) {}

void Mesh::set_mesh_ressource_ptr(const MeshRessource* new_mesh_ressource)
{
    mesh_ressource = new_mesh_ressource;
}

void Mesh::set_transform_ptr(Matrix4* new_transform) {
    transform = new_transform;
}

void Mesh::set_color(const Vector3& color) { this->color = color; }

Vector3 Mesh::get_color() const { return color; }

const Matrix3& Mesh::get_moment_of_inertia() const
{
    if (mesh_ressource == nullptr) {
        std::cout << "[WARNING] Trying to get moment of inertia with no ressource. Mesh at address : " << this << std::endl;
        return Matrix3();
    }
    return mesh_ressource->get_moment_of_inertia();
}

bool Mesh::has_ressource() const
{
    return mesh_ressource != nullptr;
}

void Mesh::draw()
{
    if (!isVisible)
        return;

    if (mesh_ressource == nullptr) {
        std::cout << "[WARNING] Trying to draw mesh with no ressource. Mesh at address : " << this << std::endl;
        return;
    }

    ofMesh mesh;
    Matrix4 transform_matrix;

    if (transform == nullptr) {
        std::cout << "[WARNING] Mesh transform is nullptr. Mesh at address : " << this << std::endl;
    }
    else {
        transform_matrix = *transform;
    }

    // Apply transform on vertices
    std::vector<Vector3> vertices = mesh_ressource->get_vertices();
    for (auto& vertex : vertices) {
        Vector4 tmp_vector = transform_matrix * Vector4(vertex, 1);
        vertex = Vector3(tmp_vector.x, tmp_vector.y, tmp_vector.z);
    }

    const std::vector<unsigned int> indices = mesh_ressource->get_indices();

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

    ofSetColor(color.x, color.y, color.z);
    mesh.draw();
    
}
