#pragma once
#include "Component/Graphics/GraphicsComponent.hpp"
#include "Matrix3.hpp"
#include "Transform.hpp"
#include "Component/Mesh/MeshRessource.hpp"
#include "Vector3.hpp"

#include "Shader.hpp"

class Mesh : public GraphicsComponent
{
public :
    Mesh() = delete;
    Mesh(const Mesh& mesh);
    Mesh& operator=(const Mesh& mesh);
    Mesh(const MeshRessource* new_mesh_ressource, const std::string& shader_path = "res/shaders/base.shader", const Vector3& offset = Vector3(), Transform* transform = nullptr);

    void set_mesh_ressource_ptr(const MeshRessource* new_mesh_ressource);
    void set_transform_ptr(Transform* new_transform);

    const Matrix3& get_moment_of_inertia() const; // TODO : remove moment of inertia from mesh, put it in rigid body
    bool has_ressource() const;
    const MeshRessource& get_mesh_ressource();
    const Vector3& get_offset() const;

    Shader& get_shader();

    float get_size() const;
    const Transform& get_transform() const;

    void draw() override;

protected:
    const MeshRessource* mesh_ressource;
    Transform* transform;
    Vector3 offset = Vector3();

    Shader shader;
};

