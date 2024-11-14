#pragma once
#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Matrix4.hpp"
#include "Component/Vector3.hpp"

class Mesh : public GraphicsComponent
{
public :
    Mesh();
    Mesh(const Mesh& mesh);
    Mesh& operator=(const Mesh& mesh);
    Mesh(Matrix4* transform);

    void set_transform_ptr(Matrix4* new_transform);
    void draw() override;

    void set_color(Vector3 color) { this->color = color; }
    Vector3 get_color() { return color; }

protected:
    virtual const std::vector<Vector3>& get_vertices() const = 0;
    virtual const std::vector<unsigned int>& get_indices() const = 0;
    virtual const Matrix3& get_moment_of_inertia() const = 0;
    Matrix4* transform;
    Vector3 color;
};

