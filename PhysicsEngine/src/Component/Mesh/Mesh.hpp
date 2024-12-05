#pragma once
#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Matrix4.hpp"
#include "Component/Mesh/MeshRessource.hpp"
#include "Component/Vector3.hpp"

class Mesh : public GraphicsComponent
{
public :
    Mesh();
    Mesh(const Mesh& mesh);
    Mesh& operator=(const Mesh& mesh);
    Mesh(const MeshRessource* new_mesh_ressource, const Vector3& color = Vector3(255, 0, 0), const Vector3& offset = Vector3(), Matrix4* transform = nullptr);

    void set_mesh_ressource_ptr(const MeshRessource* new_mesh_ressource);
    void set_transform_ptr(Matrix4* new_transform);

    void set_color(const Vector3& color);
    Vector3 get_color() const;

    void toggle_visibility() { isVisible = !isVisible; }
    void set_visibility(bool visibility) { isVisible = visibility; }

    const Matrix3& get_moment_of_inertia() const;
    bool has_ressource() const;

    float get_size() const;

    void draw() override;

protected:
    const MeshRessource* mesh_ressource;
    Matrix4* transform;
    Vector3 color;
    Vector3 offset = Vector3();
    bool isVisible = true;
};

