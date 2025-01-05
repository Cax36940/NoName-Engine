#include <iostream>

#include "Renderer.hpp"

#include "Mesh.hpp"

Mesh::Mesh(const Mesh& mesh) : mesh_ressource(mesh.mesh_ressource), transform(nullptr), color(mesh.color), offset(mesh.offset), shader(shader) {}

Mesh& Mesh::operator=(const Mesh& mesh) {
    mesh_ressource = mesh.mesh_ressource;
    transform = nullptr;
    color = mesh.color;
    offset = mesh.offset;
    shader = mesh.shader;
    return *this;
}

Mesh::Mesh(const MeshRessource* mesh_ressource, const Vector3& color, const Vector3& offset, Transform* transform) : mesh_ressource(mesh_ressource), transform(transform), color(color), offset(offset), shader("res/shaders/base_cube.shader") {}

void Mesh::set_mesh_ressource_ptr(const MeshRessource* new_mesh_ressource)
{
    mesh_ressource = new_mesh_ressource;
}

void Mesh::set_transform_ptr(Transform* new_transform) {
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

const MeshRessource& Mesh::get_mesh_ressource()
{
    return *mesh_ressource;
}

const Vector3& Mesh::get_offset() const
{
    return offset;
}

Shader& Mesh::get_shader()
{
    return shader;
}

float Mesh::get_size() const
{
    if (!mesh_ressource) {
        return 0.0f;
    }

    Matrix3 ortho_transform = Matrix3();

    if (transform) {
        ortho_transform = transform->get_ortho_transform();
    }

    const std::vector<Vector3>& vertices = mesh_ressource->get_vertices();
    float max_norm = 0.0f;
    for (auto vertex : vertices) {
        float norm = Vector3::norm2(ortho_transform * vertex);
        if (norm > max_norm) {
            max_norm = norm;
        }
    }

    return sqrt(max_norm);
}

const Transform& Mesh::get_transform() const
{
    return *transform;
}

void Mesh::draw()
{
    if (!visible)
        return;

    shader.SetUniformMat4f("u_Model", *transform);
    Renderer::Draw(mesh_ressource->get_vertex_array(), mesh_ressource->get_index_buffer(), shader);

    //ofSetColor(color.x, color.y, color.z);
}
