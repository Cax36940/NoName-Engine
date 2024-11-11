#pragma once
#include "Component/Mesh/Mesh.h"
#include "Component/Mesh/CubeMesh.h"
#include "Component/Mesh/TetrahedronMesh.h"

#include "Component/Particle.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Quaternion.hpp"
#include "Component/Vector3.hpp"

#include "Component/UpdatesComponent.hpp"

template <typename MeshType>
class RigidBody : public UpdatesComponent
{
private: 
	Particle particle;
	Matrix3 transform;
	Quaternion rotation;
	MeshType mesh;

	Matrix3 moment_of_inertia;

public:
	static_assert(std::is_base_of<Mesh, MeshType>::value, "MeshType must inherit from Mesh");

	RigidBody() :
		particle(),
		transform(),
		rotation(),
		mesh()
	{
		mesh.set_transform_ptr(&transform);
		moment_of_inertia = mesh.get_moment_of_inertia() * particle.get_mass();
	}

	RigidBody(const RigidBody& body) :
		particle(body.particle),
		transform(body.transform),
		rotation(body.rotation),
		mesh(body.mesh)
	{
		mesh.set_transform_ptr(&transform);
		moment_of_inertia = mesh.get_moment_of_inertia() * particle.get_mass();
	}

	RigidBody& operator=(const RigidBody& body) {
		particle = body.particle,
		transform = body.transform;
		rotation = body.rotation;
		mesh = body.mesh;
		mesh.set_transform_ptr(&transform);
		moment_of_inertia = mesh.get_moment_of_inertia() * particle.get_mass();
		return *this;
	}

	RigidBody(const Vector3& pos, const float& mass = 1.0f, const Matrix3& transform = Matrix3(), const Quaternion& rot = Quaternion()) :
		particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), mass),
		transform(transform),
		rotation(rot),
		mesh(&this->transform)
	{
		moment_of_inertia = mesh.get_moment_of_inertia() * particle.get_mass();
	}

	void RotateX(float alpha) {
		rotation = Quaternion(cos(alpha), sin(alpha), 0, 0) * rotation;
	}

	void RotateY(float alpha) {
		rotation = Quaternion(cos(alpha), 0, sin(alpha), 0) * rotation;
	}

	void RotateZ(float alpha) {
		rotation = Quaternion(cos(alpha), 0, 0, sin(alpha)) * rotation;
	}

	void update(float delta) override {
		//update de la rotation

		Matrix3 rotatedMatrix = Quaternion::toMatrix3(rotation);
		rotation = Quaternion();
		transform = rotatedMatrix * transform;
	}

};

using RigidCube = RigidBody<CubeMesh>;
using RigidTetrahedron = RigidBody<TetrahedronMesh>;

