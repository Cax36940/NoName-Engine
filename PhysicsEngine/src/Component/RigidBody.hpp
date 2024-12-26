#pragma once
#include "Component/Mesh/Mesh.hpp"

#include "Component/Particle.hpp"
#include "Matrix3.hpp"
#include "Transform.hpp"
#include "Quaternion.hpp"
#include "Vector3.hpp"

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
	Transform transform;

public:
	static bool enable_low_collision_gravity; // TODO : Remove use just for demo and test
	static void set_enable_low_collision_gravity(bool new_value) {
		enable_low_collision_gravity = new_value;
	}

	RigidBody() = default;
	RigidBody(const RigidBody& body);
	RigidBody(RigidBody&& body) noexcept;
	RigidBody& operator=(const RigidBody& body);
	RigidBody& operator=(RigidBody&& body) noexcept;

	RigidBody(const Vector3& pos, const float& mass = 1.0f, const Vector3& scale = Vector3(1, 1, 1), const Quaternion& angular_position = Quaternion());

	Vector3 get_position() const;
	Transform* get_transform_ptr();
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
	void add_force(const Vector3& global_position, const Vector3& force);
	void add_force_local(const Vector3& local_position, const Vector3& force);
	void add_impact(const Vector3& delta_position, const Vector3& impact_point, const Vector3& impact_velocity);

	void update(float delta) override;

};
