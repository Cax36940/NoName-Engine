/*#include <ofMaterial.h>
#include <ofMesh.h>
#include <ofGraphics.h>
#include <of3dGraphics.h>*/
// TODO : Redo display without of
#include <iostream>

#include "Mesh.hpp"

Mesh::Mesh() : mesh_ressource(nullptr), transform(nullptr), color(255, 0, 0) {}

Mesh::Mesh(const Mesh& mesh) : mesh_ressource(mesh.mesh_ressource), transform(nullptr), color(mesh.color), offset(mesh.offset) {}

Mesh& Mesh::operator=(const Mesh& mesh) {
    mesh_ressource = mesh.mesh_ressource;
    transform = nullptr;
    color = mesh.color;
    offset = mesh.offset;
    return *this;
}

Mesh::Mesh(const MeshRessource* mesh_ressource, const Vector3& color, const Vector3& offset, Transform* transform) : mesh_ressource(mesh_ressource), transform(transform), color(color), offset(offset) {}

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

/*const ofMesh& Mesh::get_cached_mesh() const
{
    return cached_mesh;
}*/

const Transform& Mesh::get_transform() const
{
    return *transform;
}

void Mesh::draw()
{
    if (!visible)
        return;

    if (!(cached_transform == *transform)) {
        meshNeedsUpdate = true;
    }
    
    if (meshNeedsUpdate) {
        update_mesh();
    }

    //ofSetColor(color.x, color.y, color.z);
    //cached_mesh.draw();
}

void Mesh::update_mesh()
{
    if (mesh_ressource == nullptr) {
        std::cout << "[WARNING] Trying to draw mesh with no ressource. Mesh at address : " << this << std::endl;
        return;
    }

    if (transform == nullptr) {
        std::cout << "[WARNING] Mesh transform is nullptr. Mesh at address : " << this << std::endl;
    }
    else {
        cached_transform = *transform;
    }
    //cached_mesh.clear();

    // Apply transform on vertices
    std::vector<Vector3> vertices = mesh_ressource->get_vertices();
    for (auto& vertex : vertices) {
        vertex += offset;
        Vector4 tmp_vector = cached_transform * Vector4(vertex, 1);
        vertex = Vector3(tmp_vector.x, tmp_vector.y, tmp_vector.z);
    }

    const std::vector<unsigned int> indices = mesh_ressource->get_indices();

   /* std::vector<ofDefaultVertexType> tmp_vertices;
    std::vector<ofIndexType> tmp_indices;
    std::vector<ofDefaultNormalType> tmp_normals;
    tmp_vertices.reserve(indices.size());
    tmp_indices.reserve(indices.size());
    tmp_normals.reserve(indices.size());

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
        tmp_vertices.emplace_back(v0);
        tmp_vertices.emplace_back(v1);
        tmp_vertices.emplace_back(v2);

        // Add indices to mesh
        tmp_indices.emplace_back(i);
        tmp_indices.emplace_back(i + 1);
        tmp_indices.emplace_back(i + 2);

        // Calculate the face normal
        ofDefaultVertexType edge1 = v1 - v0;
        ofDefaultVertexType edge2 = v2 - v0;
        ofDefaultVertexType face_normal = glm::normalize(glm::cross(edge1, edge2));

        // Add normals to mesh
        tmp_normals.emplace_back(face_normal);
        tmp_normals.emplace_back(face_normal);
        tmp_normals.emplace_back(face_normal);
    }

    cached_mesh.addVertices(tmp_vertices);
    cached_mesh.addIndices(tmp_indices);
    cached_mesh.addNormals(tmp_normals);

    meshNeedsUpdate = false;
    */
}
