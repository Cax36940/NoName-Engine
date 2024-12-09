#include "RigidBodyFactory.hpp"

#include "Component/Mesh/CubeMesh.hpp"
#include "Component/Mesh/DodecahedronMesh.hpp"
#include "Component/Mesh/IcosahedronMesh.hpp"
#include "Component/Mesh/OctahedronMesh.hpp"
#include "Component/Mesh/PlaneMesh.hpp"
#include "Component/Mesh/TetrahedronMesh.hpp"

static struct RigidBodyArgs {
	float mass;
	Vector3 scale;
	Quaternion rot;
	Vector3 color;
	const MeshRessource* mesh_ressource;
};

static RigidBodyArgs rigid_body_args_list[] = {
 {25, Vector3(1, 1, 1), Quaternion(), Vector3(255, 0, 0), &CubeMesh::get_instance()},				// CUBE
 {4.5, Vector3(1, 1, 1), Quaternion(), Vector3(255, 0, 0), &DodecahedronMesh::get_instance()},		// DODECAHEDRON
 {4, Vector3(1, 1, 1), Quaternion(), Vector3(255, 0, 0), &IcosahedronMesh::get_instance()},		// ICOSAHEDRON
 {3, Vector3(1, 1, 1), Quaternion(), Vector3(255, 0, 0), &OctahedronMesh::get_instance()},			// OCTAHEDRON
 {1.5, Vector3(1, 1, 1), Quaternion(), Vector3(255, 0, 0), &TetrahedronMesh::get_instance()},		// TETRAHEDRON
 {0, Vector3(0, 0, 0), Quaternion(), Vector3(0, 0, 0), nullptr},		// UNKNOWN
 {100000000.0f, Vector3(100, 1, 100), Quaternion(), Vector3(200, 200, 200), &PlaneMesh::get_instance()},			// PLANE
};

DefaultRigidBody RigidBodyFactory::createRigidBody(enum RigidBodyType type, const Vector3& pos, const Vector3& center_of_gravity)
{
	const RigidBodyArgs& rigid_body_args = rigid_body_args_list[type];
	return DefaultRigidBody(RigidBody(pos, rigid_body_args.mass, rigid_body_args.scale, rigid_body_args.rot), Mesh(rigid_body_args.mesh_ressource, rigid_body_args.color, center_of_gravity));
}

