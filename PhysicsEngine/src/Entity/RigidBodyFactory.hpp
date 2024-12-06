#pragma once
#include "DefaultRigidBody.hpp"

enum RigidBodyType {
	CUBE,
	DODECAHEDRON,
	ICOSAHEDRON,
	OCTAHEDRON,
	PLANE,
	TETRAHEDRON,
	PARTICLE_TYPE_COUNT
};

class RigidBodyFactory
{
public:
	static DefaultRigidBody createRigidBody(enum RigidBodyType type, const Vector3& pos, const Vector3& center_of_gravity = Vector3());
};

