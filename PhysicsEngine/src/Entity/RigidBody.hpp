#pragma once
#include "Component/Particle.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Quaternion.hpp"
#include "Component/Vector3.hpp"

class RigidBody
{
private: 
	Particle particle;
	Matrix3 matrice;
	Quaternion quaternion;
	//ressources* mesh; ??

public:
	RigidBody() = default;
	RigidBody::RigidBody(Vector3 pos, float mass, Matrix3 m, Quaternion q);


	void RotateX();
	void RotateY();
	void RotateZ();

	Matrix3 quaternionToMatrix3(Quaternion q);

	void update(float delta);

};

