#include "RigidBodyFactory.h"

static struct RigidBodyArgs {
	float mass;
	Matrix4 transform;
	Quaternion rot;
};

static RigidBodyArgs rigid_body_args_list[] = {
 {250, 15 * Matrix3(), Quaternion()},	// CUBE
 {150,  15 * Matrix3(), Quaternion()},	// TETRAHEDRON
 {400,  15 * Matrix3(), Quaternion()},	// OCTAHEDRON
};

RigidCube RigidBodyFactory::createRigidCube(const Vector3& pos)
{
	const RigidBodyArgs& rigid_body_args = rigid_body_args_list[0];
	return RigidCube(pos, rigid_body_args.mass, rigid_body_args.transform, rigid_body_args.rot);
}



RigidTetrahedron RigidBodyFactory::createRigidTetrahedron(const Vector3& pos)
{
	const RigidBodyArgs& rigid_body_args = rigid_body_args_list[1];
	return RigidTetrahedron(pos, rigid_body_args.mass, rigid_body_args.transform, rigid_body_args.rot);
}



RigidOctahedron RigidBodyFactory::createRigidOctahedron(const Vector3& pos)
{
	const RigidBodyArgs& rigid_body_args = rigid_body_args_list[2];
	return RigidOctahedron(pos, rigid_body_args.mass, rigid_body_args.transform, rigid_body_args.rot);
}


