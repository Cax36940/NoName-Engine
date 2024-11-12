#pragma once
#include "RigidBody.hpp"

class RigidBodyFactory
{
public:
	static RigidCube createRigidCube(const Vector3& pos);
	

	static RigidTetrahedron createRigidTetrahedron(const Vector3& pos);
	

	static RigidOctahedron createRigidOctahedron(const Vector3& pos);
	
};

