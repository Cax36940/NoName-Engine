#include "RigidBodyFactory.hpp"

#include "Component/Mesh/CubeMesh.hpp"
#include "Component/Mesh/DodecahedronMesh.hpp"
#include "Component/Mesh/IcosahedronMesh.hpp"
#include "Component/Mesh/OctahedronMesh.hpp"
#include "Component/Mesh/TetrahedronMesh.hpp"

static struct RigidBodyArgs {
	float mass;
	Vector3 scale;
	Quaternion rot;
	Vector3 color;
	const MeshRessource* mesh_ressource;
};

static RigidBodyArgs rigid_body_args_list[] = {
 {250, Vector3(15, 15, 15), Quaternion(), Vector3(255, 0, 0), &CubeMesh::get_instance()},				// CUBE
 {450, Vector3(15, 15, 15), Quaternion(), Vector3(255, 0, 0), &DodecahedronMesh::get_instance()},		// DODECAHEDRON
 {400, Vector3(15, 15, 15), Quaternion(), Vector3(255, 0, 0), &IcosahedronMesh::get_instance()},		// ICOSAHEDRON
 {300, Vector3(15, 15, 15), Quaternion(), Vector3(255, 0, 0), &OctahedronMesh::get_instance()},			// OCTAHEDRON
 {150, Vector3(15, 15, 15), Quaternion(), Vector3(255, 0, 0), &TetrahedronMesh::get_instance()},		// TETRAHEDRON
};

DefaultRigidBody RigidBodyFactory::createRigidBody(enum RigidBodyType type, const Vector3& pos)
{
	const RigidBodyArgs& rigid_body_args = rigid_body_args_list[type];
	return DefaultRigidBody(RigidBody(pos, rigid_body_args.mass, rigid_body_args.scale, rigid_body_args.rot), Mesh(rigid_body_args.mesh_ressource, rigid_body_args.color));
}

