#pragma once
#include "Component/Graphics/GraphicsComponent.hpp"
#include "Matrix3.hpp"
#include "Transform.hpp"
#include "Component/Mesh/MeshRessource.hpp"
#include "Vector3.hpp"

// TODO : remove cache mesh

class Mesh : public GraphicsComponent
{
public :
    Mesh();
    Mesh(const Mesh& mesh);
    Mesh& operator=(const Mesh& mesh);
    Mesh(const MeshRessource* new_mesh_ressource, const Vector3& color = Vector3(255, 0, 0), const Vector3& offset = Vector3(), Transform* transform = nullptr);

    void set_mesh_ressource_ptr(const MeshRessource* new_mesh_ressource);
    void set_transform_ptr(Transform* new_transform);

    void set_color(const Vector3& color);
    Vector3 get_color() const;

    const Matrix3& get_moment_of_inertia() const;
    bool has_ressource() const;
    const MeshRessource& get_mesh_ressource();
    const Vector3& get_offset() const;

    float get_size() const;
    //const ofMesh& get_cached_mesh() const;
    const Transform& get_transform() const;

    void draw() override;

protected:
    const MeshRessource* mesh_ressource;
    Transform* transform;
    Vector3 color;
    Vector3 offset = Vector3();
    bool meshNeedsUpdate = true;
    //ofMesh cached_mesh;
    Transform cached_transform; // Used to check if mesh needs to be updated

    void update_mesh();
};

