#include "SphereCollider.hpp"

#include <iostream>

SphereCollider::SphereCollider(const Vector3& pos, const float& size, Particle* physical_body)
	: position(pos), size(size), physical_body(physical_body)
{
	CollidersComponentRegistry::add(this);
}

void SphereCollider::set_position(const Vector3& pos)
{
	position = pos;
}

void SphereCollider::set_size(const float& new_size)
{
	size = new_size;
}

Vector3 SphereCollider::get_position() const
{
	return position;
}

float SphereCollider::get_size() const
{
	return size;
}
