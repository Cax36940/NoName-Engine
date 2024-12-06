#pragma once

#include "Component/Mesh/Mesh.hpp"
#include "Component/RigidBody.hpp"
#include "Component/Physics/Collider/SphereCollider.hpp"

class DefaultRigidBody {
public:
	RigidBody rigid_body;
	Mesh mesh;
	SphereCollider collider;

	DefaultRigidBody() = default;
	DefaultRigidBody(const DefaultRigidBody& drb) :
		rigid_body(drb.rigid_body),
		mesh(drb.mesh),
		collider(drb.collider.get_size(), rigid_body.get_physical_particle()) {
		mesh.set_transform_ptr(rigid_body.get_transform_ptr());
	}

	DefaultRigidBody& operator=(const DefaultRigidBody& drb) {
		rigid_body = drb.rigid_body;
		mesh = drb.mesh;
		mesh.set_transform_ptr(rigid_body.get_transform_ptr());
		collider = SphereCollider(drb.collider.get_size(), rigid_body.get_physical_particle());
		return *this;
	}

	DefaultRigidBody(const RigidBody& rigid_body, const Mesh& mesh) :
		rigid_body(rigid_body),
		mesh(mesh),
		collider(mesh.get_size(), this->rigid_body.get_physical_particle()){
		this->mesh.set_transform_ptr(this->rigid_body.get_transform_ptr());
		this->rigid_body.set_moment_inertia(this->mesh.get_moment_of_inertia());
	}

	Vector3 get_position() const {
		return rigid_body.get_position();
	}

	Mesh* get_mesh() {
		return &mesh;
	}

	Particle* get_physical_particle()
	{
		return rigid_body.get_physical_particle();
	}

	void add_force(const Vector3& force) {
		rigid_body.add_force(force);
	}

	void add_force(const Vector3& local_pos, const Vector3& force) {
		rigid_body.add_force(local_pos, force);
	}

};