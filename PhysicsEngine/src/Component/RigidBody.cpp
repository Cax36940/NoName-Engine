#pragma once
#include "Component/RigidBody.hpp"


RigidBody::RigidBody(const Vector3& pos, const float& mass, const Vector3& scale, const Quaternion& angular_position) :
	particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), mass),
	angular_position(angular_position),
	angular_velocity(),
	accum_torque(),
	scale(scale),
	inv_moment_inertia(0, 0, 0),
	transform(Quaternion::toMatrix3(angular_position) * Matrix3(scale.x, scale.y, scale.z), pos) {}

Vector3 RigidBody::get_position() const {
	return particle.get_position();
}

Matrix4* RigidBody::get_transform_ptr()
{
	return &transform;
}

Particle* RigidBody::get_physical_particle()
{
	return &particle;
}

void RigidBody::set_moment_inertia(const Matrix3& new_moment_inertia)
{
	inv_moment_inertia = Matrix3::inv(new_moment_inertia) * particle.get_inv_mass();
}

void RigidBody::rotate_x(float alpha) {
	angular_position = Quaternion(cos(alpha), sin(alpha), 0, 0) * angular_position;
}

void RigidBody::rotate_y(float alpha) {
	angular_position = Quaternion(cos(alpha), 0, sin(alpha), 0) * angular_position;
}

void RigidBody::rotate_z(float alpha) {
	angular_position = Quaternion(cos(alpha), 0, 0, sin(alpha)) * angular_position;
}

void RigidBody::set_velocity(float x, float y, float z)
{
	particle.set_velocity(Vector3(x, y, z));
}

void RigidBody::set_angular_velocity(const Vector3& new_angular_velocity) {
	angular_velocity = new_angular_velocity;
}

void RigidBody::set_angular_velocity(float x, float y, float z) {
	angular_velocity.x = x;
	angular_velocity.y = y;
	angular_velocity.z = z;
}

void RigidBody::set_scale(float x, float y, float z) {
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

void RigidBody::add_force(const Vector3& torque) {
	accum_torque += torque;
	particle.add_force(torque);
}

void RigidBody::add_force(const Vector3& local_position, const Vector3& force)
{
	Vector3 resultant_torque = Vector3::cross(local_position, force);
	accum_torque += resultant_torque;
	
	particle.add_force(force);
}

void RigidBody::update(float delta) {
	particle.update(delta);

	// Newton second law
	Vector3 angular_acceleration = inv_moment_inertia * accum_torque;
	accum_torque = Vector3();

	// Update angular velocity
	angular_velocity += angular_acceleration * delta;

	// Rotate
	float angle = Vector3::norm(delta * angular_velocity);
	if (angle != 0) {
		Quaternion velocity_quat(cos(angle), (sin(angle) / angle) * delta * angular_velocity);
		angular_position = velocity_quat * angular_position;

		// Update moment of inertia J = R*J-1*R-1
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
