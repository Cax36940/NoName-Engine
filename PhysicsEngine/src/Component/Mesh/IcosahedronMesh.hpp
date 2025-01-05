#pragma once
#include "MeshRessource.hpp"
#define GOLDEN_RATIO 1.61803398875 

class IcosahedronMesh : public MeshRessource {
public:
	IcosahedronMesh(const IcosahedronMesh&) = delete;
	IcosahedronMesh& operator=(const IcosahedronMesh&) = delete;

	static const IcosahedronMesh& get_instance() {
		static IcosahedronMesh icosahedron_mesh;
		return icosahedron_mesh;
	}

	const std::vector<Vector3>& get_vertices() const override { return vertices; }
	const std::vector<unsigned int>& get_indices() const override { return indices; }
	const Matrix3& get_moment_of_inertia() const override { return moment_of_inertia; }

private:
	IcosahedronMesh() {
		init_ressource();
	}

	const std::vector<Vector3> IcosahedronMesh::vertices {
		Vector3(0, GOLDEN_RATIO, 1), 
		Vector3(0, GOLDEN_RATIO, -1), 
		Vector3(0, -GOLDEN_RATIO, -1),
		Vector3(0, -GOLDEN_RATIO, 1),			
		Vector3(-1, 0, GOLDEN_RATIO), 
		Vector3(-1, 0, -GOLDEN_RATIO), 
		Vector3(1, 0, -GOLDEN_RATIO), 
		Vector3(1, 0, GOLDEN_RATIO),	
		Vector3(-GOLDEN_RATIO, 1, 0), 
		Vector3(-GOLDEN_RATIO, -1, 0), 
		Vector3(GOLDEN_RATIO, -1, 0), 
		Vector3(GOLDEN_RATIO, 1, 0)}; 

	const std::vector<unsigned int> IcosahedronMesh::indices {
		 0,  4,  7,
		 0,  7, 11,
		 0, 11,  1,
		 0,  1,  8,
		 0,  8,  4,

		 7,  4,  3,
		11,  7, 10,
		 1, 11,  6,
		 8,  1,  5,
		 4,  8,  9,
	
		 3, 10,  7,
		10,  6, 11,
		 6,  5,  1,
		 5,  9,  8,
		 9,  3,  4,
	
		10,  3,  2,
		 6, 10,  2,
		 5,  6,  2,
		 9,  5,  2,
		 3,  9,  2 };

	const Matrix3 IcosahedronMesh::moment_of_inertia = Matrix3();
	
};