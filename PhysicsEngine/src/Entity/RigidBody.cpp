#include "RigidBody.hpp"

RigidBody::RigidBody(Vector3 pos, float mass, Matrix3 m, Quaternion q)
{
	this->particle = Particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), mass);
	this->matrice = m;
	this->quaternion = q;
}

void RigidBody::RotateX()
{
}

void RigidBody::RotateY()
{
}

void RigidBody::RotateZ()
{
}


void RigidBody::update(float delta)
{

	//update de la rotation
	Matrix3 rotatedMatrix = Quaternion::toMatrix3(this->quaternion);
	this->matrice = this->matrice * rotatedMatrix;


	//update de la translation
	this->particle.update(delta);

}
