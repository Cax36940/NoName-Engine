#include "RigidBody.hpp"

RigidBody::RigidBody()
{
	mesh.set_transform_ptr(&transform);
}

RigidBody::RigidBody(const RigidBody& body) :
	particle(body.particle),
	transform(body.transform),
	quaternion(body.quaternion),
	mesh(body.mesh)
{
	mesh.set_transform_ptr(&transform);
}

RigidBody& RigidBody::operator=(const RigidBody& body)
{
	particle = body.particle,
	transform = body.transform;
	quaternion = body.quaternion;
	mesh = body.mesh;
	mesh.set_transform_ptr(&transform);
	return *this;
}

RigidBody::RigidBody(const Vector3& pos, const float& mass, const Matrix3& transform, const Quaternion& quat) :
	particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), mass),
	transform(transform),
	quaternion(quat),
	mesh(&this->transform){}

void RigidBody::RotateX()
{
}

void RigidBody::RotateY()
{
}

void RigidBody::RotateZ(float alpha)
{
	quaternion = Quaternion(cos(alpha), 0, 0, sin(alpha)) * quaternion;
}


void RigidBody::update(float delta)
{

	//update de la rotation
	Matrix3 rotatedMatrix = Quaternion::toMatrix3(quaternion);
	quaternion = Quaternion();
	transform = rotatedMatrix * transform;


	//update de la translation
	particle.update(delta);

}
