#pragma once
#include "MeshRessource.hpp"

class PlaneMesh : public MeshRessource {
public:
	PlaneMesh(const PlaneMesh&) = delete;
	PlaneMesh& operator=(const PlaneMesh&) = delete;

	static const PlaneMesh& get_instance() {
		static PlaneMesh plane_mesh;
		return plane_mesh;
	}

	const std::vector<Vector3>& get_vertices() const override { return get_instance().vertices; }
	const std::vector<unsigned int>& get_indices() const override { return get_instance().indices; }
	const Matrix3& get_moment_of_inertia() const override { return get_instance().moment_of_inertia; }

private:
	PlaneMesh() = default;

	const std::vector<Vector3> vertices{
		Vector3( 1,  0,  1),
		Vector3( 1,  0, -1),
		Vector3(-1,  0, -1),
		Vector3(-1,  0,  1) };

	const std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3 };

	const Matrix3 moment_of_inertia = Matrix3(
		Vector3(1., 0, 0),
		Vector3(0, 1., 0),
		Vector3(0, 0, 1.)
	);
};


