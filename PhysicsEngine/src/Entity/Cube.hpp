#pragma once

#include "Component/Mesh/Mesh.hpp"
#include "Component/Mesh/CubeMesh.hpp"
#include "Component/Mesh/DodecahedronMesh.hpp"
#include "Transform.hpp"
#include "Vector3.hpp"

class Cube {
private :
	Transform transform;

public:
	Mesh mesh;
	Cube(const Vector3& pos) : 
		transform(Matrix3(), pos),
		mesh(&CubeMesh::get_instance()) {
		mesh.set_transform_ptr(&transform);
	};

	Cube(float x, float y, float z) : 
		transform(Matrix3(), Vector3(x, y, z)),
		mesh(&DodecahedronMesh::get_instance()) {
		mesh.set_transform_ptr(&transform);
	};
};