#pragma once
#include "MeshRessource.hpp"

class TetrahedronMesh : public MeshRessource {
public:
	TetrahedronMesh(const TetrahedronMesh&) = delete;
	TetrahedronMesh& operator=(const TetrahedronMesh&) = delete;

	static const TetrahedronMesh& get_instance() {
		static TetrahedronMesh cube_mesh;
		return cube_mesh;
	}

	const std::vector<Vector3>& get_vertices() const override { return vertices; }
	const std::vector<unsigned int>& get_indices() const override { return indices; }
	const Matrix3& get_moment_of_inertia() const override { return moment_of_inertia; }

private:
	TetrahedronMesh() {
		init_ressource();
	}

	const std::vector<Vector3> TetrahedronMesh::vertices {	
		Vector3( 1,  1,  1),
		Vector3( 1, -1, -1),
		Vector3(-1,  1, -1),
		Vector3(-1, -1,  1) };

	const std::vector<unsigned int> TetrahedronMesh::indices {   
		0, 1, 2,
		0, 2, 3,
		0, 3, 1,
		1, 2, 3 };

	const Matrix3 TetrahedronMesh::moment_of_inertia = Matrix3();
};