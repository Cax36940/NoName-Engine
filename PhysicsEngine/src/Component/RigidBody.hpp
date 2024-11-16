#pragma once
#include "Component/Mesh/Mesh.hpp"

#include "Component/Particle.hpp"
#include "Component/Matrix3.hpp"
#include "Component/Matrix4.hpp"
#include "Component/Quaternion.hpp"
#include "Component/Vector3.hpp"

#include "Component/UpdatesComponent.hpp"

class RigidBody : public UpdatesComponent
{
private: 
	Particle particle;

	Quaternion angular_position;
	Vector3 angular_velocity;
	Vector3 accum_torque;
	Vector3 scale = Vector3(1, 1, 1);

	Matrix3 inv_moment_inertia;
	Matrix4 transform;

public:

	RigidBody() = default;
	RigidBody(const RigidBody& body) = default;
	RigidBody(RigidBody&& body) = default;
	RigidBody& operator=(const RigidBody& body) = default;
	RigidBody& operator=(RigidBody&& body) = default;

	RigidBody(const Vector3& pos, const float& mass = 1.0f, const Vector3& scale = Vector3(1, 1, 1), const Quaternion& angular_position = Quaternion());

	Vector3 get_position() const;
	Matrix4* get_transform_ptr();
	Particle* get_physical_particle();

	void set_moment_inertia(const Matrix3& new_moment_inertia);

	void set_velocity(float x, float y, float z);
	void set_angular_velocity(const Vector3& new_angular_velocity);
	void set_angular_velocity(float x, float y, float z);

	void set_scale(float x, float y, float z);

	void rotate_x(float alpha);
	void rotate_y(float alpha);
	void rotate_z(float alpha);

	void add_force(const Vector3& torque);

	void update(float delta) override;

};
