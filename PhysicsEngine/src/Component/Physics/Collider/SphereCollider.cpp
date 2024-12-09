#include "SphereCollider.hpp"

SphereCollider::SphereCollider(const float& size, Particle* physical_body, Mesh* collider_mesh, RigidBody* rigid_body)
	: size(size), physical_body(physical_body), collider_mesh(collider_mesh), rigid_body(rigid_body)
{
	CollidersComponentRegistry::add(this);
}

void SphereCollider::set_size(const float& new_size)
{
	size = new_size;
}

float SphereCollider::get_size() const
{
	return size;
}

Mesh* SphereCollider::get_mesh_ptr() const {
	return collider_mesh;
}

RigidBody* SphereCollider::get_rigibody_ptr() const {
	return rigid_body;
}
