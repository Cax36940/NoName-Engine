#pragma once
#include "Component/Matrix3.hpp"
#include "Component/Vector3.hpp"

class MeshRessource {
public:
    virtual const std::vector<Vector3>& get_vertices() const = 0;
    virtual const std::vector<unsigned int>& get_indices() const = 0;
    virtual const Matrix3& get_moment_of_inertia() const = 0;

protected:
    MeshRessource() = default;
};
