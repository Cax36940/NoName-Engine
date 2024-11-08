#pragma once
#include "Component/Graphics/GraphicsComponent.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Vector3.hpp"

class Mesh : public GraphicsComponent
{
public :
    Mesh();
    Mesh(const Mesh& mesh);
    Mesh& operator=(const Mesh& mesh);
    Mesh(Matrix3* transform);
    void draw() override;

protected:
    virtual const std::vector<Vector3>& get_vertices() const = 0;
    virtual const std::vector<unsigned int>& get_indices() const = 0;
    Matrix3* transform;
};

