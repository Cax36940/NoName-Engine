#pragma once

#include "Component/Mesh/Mesh.hpp"
#include "Component/Mesh/CubeMesh.hpp"
#include "Component/Mesh/DodecahedronMesh.hpp"
#include "Transform.hpp"
#include "Vector3.hpp"

class Cube {

public:
	Transform transform;
	Mesh mesh;

	Cube(const Vector3& pos, const std::string& shader_path) :
		transform(Matrix3(), pos),
		mesh(&CubeMesh::get_instance(), shader_path) {
		mesh.set_transform_ptr(&transform);
	};

	Cube(float x, float y, float z, const std::string& shader_path) : 
		transform(Matrix3(), Vector3(x, y, z)),
		mesh(&CubeMesh::get_instance(), shader_path) {
		mesh.set_transform_ptr(&transform);
	};

	
};