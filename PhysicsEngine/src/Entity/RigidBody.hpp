#pragma once
#include "Component/Mesh/CubeMesh.h"
#include "Component/Particle.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Quaternion.hpp"
#include "Component/Vector3.hpp"

class RigidBody
{
private: 
	Particle particle;
	Matrix3 transform;
	Quaternion quaternion;
	CubeMesh mesh;

public:
	RigidBody();
	RigidBody(const RigidBody& body);
	RigidBody& operator=(const RigidBody& body);

	RigidBody::RigidBody(const Vector3& pos, const float& mass, const Matrix3& transform, const Quaternion& quat);

	void RotateX();
	void RotateY();
	void RotateZ();

	void update(float delta);

};

