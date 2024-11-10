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
	Quaternion quaternion;
	MeshType mesh;

public:
	static_assert(std::is_base_of<Mesh, MeshType>::value, "MeshType must inherit from Mesh");

	RigidBody() :
		particle(),
		transform(),
		quaternion(),
		mesh()
	{
		mesh.set_transform_ptr(&transform);
	}

	RigidBody(const RigidBody& body) :
		particle(body.particle),
		transform(body.transform),
		quaternion(body.quaternion),
		mesh(body.mesh)
	{
		mesh.set_transform_ptr(&transform);
	}

	RigidBody& operator=(const RigidBody& body) {
		particle = body.particle,
		transform = body.transform;
		quaternion = body.quaternion;
		mesh = body.mesh;
		mesh.set_transform_ptr(&transform);
		return *this;
	}

	RigidBody(const Vector3& pos, const float& mass = 1.0f, const Matrix3& transform = Matrix3(), const Quaternion& quat = Quaternion()) :
		particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), mass),
		transform(transform),
		quaternion(quat),
		mesh(&this->transform) {}

	void RotateX(float alpha) {
		quaternion = Quaternion(cos(alpha), sin(alpha), 0, 0) * quaternion;
	}

	void RotateY(float alpha) {
		quaternion = Quaternion(cos(alpha), 0, sin(alpha), 0) * quaternion;
	}

	void RotateZ(float alpha) {
		quaternion = Quaternion(cos(alpha), 0, 0, sin(alpha)) * quaternion;
	}

	void update(float delta) override {
		//update de la rotation
		Matrix3 rotatedMatrix = Quaternion::toMatrix3(quaternion);
		quaternion = Quaternion();
		transform = rotatedMatrix * transform;
	}

};

using RigidCube = RigidBody<CubeMesh>;
using RigidTetrahedron = RigidBody<TetrahedronMesh>;

