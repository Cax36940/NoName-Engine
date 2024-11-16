#pragma once
#include "Component/Mesh/Mesh.hpp"
#include "Component/Mesh/CubeMesh.hpp"
#include "Component/Mesh/DodecahedronMesh.hpp"
#include "Component/Mesh/IcosahedronMesh.hpp"
#include "Component/Mesh/OctahedronMesh.hpp"
#include "Component/Mesh/TetrahedronMesh.hpp"

#include "Component/Particle.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Matrix4.hpp"
#include "Component/Quaternion.hpp"
#include "Component/Vector3.hpp"

#include "Component/UpdatesComponent.hpp"

template <typename MeshType>
class RigidBody : public UpdatesComponent
{
private: 
	Particle particle;

	Quaternion angular_position;
	Vector3 angular_velocity;
	Vector3 accum_torque;
	Vector3 scale;

	MeshType mesh;
	Matrix3 inv_moment_inertia;
	Matrix4 transform;

public:
	static_assert(std::is_base_of<Mesh, MeshType>::value, "MeshType must inherit from Mesh");

	RigidBody() :
		particle(),
		angular_position(),
		angular_velocity(),
		accum_torque(),
		scale(1, 1, 1),
		mesh(),
		inv_moment_inertia(),
		transform()
	{
		mesh.set_transform_ptr(&transform);
		inv_moment_inertia = Matrix3::inv(mesh.get_moment_of_inertia() * particle.get_mass());
	}

	RigidBody(const RigidBody& body) :
		particle(body.particle),
		angular_position(body.angular_position),
		angular_velocity(body.angular_velocity),
		accum_torque(body.accum_torque),
		scale(body.scale),
		mesh(body.mesh)
		inv_moment_inertia(),
		transform(body.transform)
	{
		mesh.set_transform_ptr(&transform);
		inv_moment_inertia = Matrix3::inv(mesh.get_moment_of_inertia() * particle.get_mass());
	}

	RigidBody& operator=(const RigidBody& body) {
		particle = body.particle,
		angular_position = body.angular_position;
		angular_velocity = body.angular_velocity;
		accum_torque = body.accum_torque;
		scale = body.scale;
		mesh = body.mesh;
		mesh.set_transform_ptr(&transform);
		inv_moment_inertia = Matrix3::inv(mesh.get_moment_of_inertia() * particle.get_mass());
		transform = body.transform;
		return *this;
	}

	RigidBody(const Vector3& pos, const float& mass = 1.0f, const Vector3& scale = Vector3(1, 1, 1), const Quaternion& angular_position = Quaternion()) :
		particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), mass),
		angular_position(angular_position),
		angular_velocity(),
		accum_torque(),
		scale(scale),
		mesh(&this->transform),
		inv_moment_inertia(),
		transform(Quaternion::toMatrix3(angular_position) * Matrix3(scale.x, scale.y, scale.z), pos)
	{
		inv_moment_inertia = Matrix3::inv(mesh.get_moment_of_inertia() * particle.get_mass());
	}

	Vector3 get_position() const {
		return particle.get_position();
	}

	void rotate_x(float alpha) {
		angular_position = Quaternion(cos(alpha), sin(alpha), 0, 0) * angular_position;
	}

	void rotate_y(float alpha) {
		angular_position = Quaternion(cos(alpha), 0, sin(alpha), 0) * angular_position;
	}

	void rotate_z(float alpha) {
		angular_position = Quaternion(cos(alpha), 0, 0, sin(alpha)) * angular_position;
	}

	void set_angular_velocity(const Vector3& new_angular_velocity) {
		angular_velocity = new_angular_velocity;
	}

	void set_angular_velocity(float x, float y, float z) {
		angular_velocity.x = x;
		angular_velocity.y = y;
		angular_velocity.z = z;
	}

	void set_scale(float x, float y, float z) {
		scale.x = x;
		scale.y = y;
		scale.z = z;
	}

	void add_force(const Vector3& torque) {
		accum_torque += torque;
	}

	void update(float delta) override {
		// Newton second law
		Vector3 angular_acceleration = inv_moment_inertia * accum_torque;
		accum_torque = Vector3();

		// Update angular velocity
		angular_velocity += angular_acceleration * delta;
		
		// Rotate
		float angle = Vector3::norm(delta * angular_velocity);
		if(angle != 0){
			Quaternion velocity_quat(cos(angle), (sin(angle) / angle) * delta * angular_velocity);
			angular_position = velocity_quat * angular_position;

			// Update moment of inertia
			inv_moment_inertia = Quaternion::toMatrix3(angular_position) * inv_moment_inertia *
				Quaternion::toMatrix3(Quaternion::inv(angular_position));
		}

		// Update transformation matrix
		Matrix3 rotation_matrix = Quaternion::toMatrix3(angular_position);
		rotation_matrix.x *= scale.x;
		rotation_matrix.y *= scale.y;
		rotation_matrix.z *= scale.z;
		transform = Matrix4(rotation_matrix, particle.get_position());
	}

};

using RigidCube = RigidBody<CubeMesh>;
using RigidTetrahedron = RigidBody<TetrahedronMesh>;
using RigidOctahedron = RigidBody<OctahedronMesh>;
using RigidIcosahedron = RigidBody<IcosahedronMesh>;
using RigidDodecahedron = RigidBody<DodecahedronMesh>;
