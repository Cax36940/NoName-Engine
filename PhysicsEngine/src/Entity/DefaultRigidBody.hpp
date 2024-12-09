#pragma once

#include "Component/Mesh/Mesh.hpp"
#include "Component/Mesh/CubeMesh.hpp" // get_instance
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
		collider(drb.collider.get_size(), rigid_body.get_physical_particle(), &mesh, &rigid_body) {
		mesh.set_transform_ptr(rigid_body.get_transform_ptr());
	}

	DefaultRigidBody& operator=(const DefaultRigidBody& drb) {
		rigid_body = drb.rigid_body;
		mesh = drb.mesh;
		mesh.set_transform_ptr(rigid_body.get_transform_ptr());
		collider = SphereCollider(drb.collider.get_size(), rigid_body.get_physical_particle(), &mesh, &rigid_body);
		return *this;
	}

	DefaultRigidBody(const RigidBody& rigid_body, const Mesh& mesh) :
		rigid_body(rigid_body),
		mesh(mesh),
		collider(0, this->rigid_body.get_physical_particle(), &this->mesh, &this->rigid_body){
		this->mesh.set_transform_ptr(this->rigid_body.get_transform_ptr());
		collider.set_size(this->mesh.get_size());
		this->rigid_body.set_moment_inertia(this->mesh.get_moment_of_inertia());
	}

	DefaultRigidBody(const Vector3& pos) : // Directly create a Cube
		rigid_body(pos, 25),
		mesh(&CubeMesh::get_instance()),
		collider(0, rigid_body.get_physical_particle(), &mesh, &rigid_body) {
		this->mesh.set_transform_ptr(rigid_body.get_transform_ptr());
		collider.set_size(this->mesh.get_size());
		this->rigid_body.set_moment_inertia(mesh.get_moment_of_inertia());
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

	void set_apply_gravity(bool new_value) {
		rigid_body.get_physical_particle()->set_apply_gravity(new_value);
	};

	void rotate_x(float alpha) {
		rigid_body.rotate_x(alpha);
	};

	void rotate_y(float alpha) {
		rigid_body.rotate_y(alpha);
	};

	void rotate_z(float alpha) {
		rigid_body.rotate_z(alpha);
	};

};