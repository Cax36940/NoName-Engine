#include "SphereCollider.hpp"

SphereCollider::SphereCollider(const float& size, Particle* physical_body, Mesh* collision_mesh)
	: size(size), physical_body(physical_body), collision_mesh(collision_mesh)
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
	return collision_mesh;
}
