#include "SphereCollider.hpp"

SphereCollider::SphereCollider(const float& size, Particle* physical_body)
	: size(size), physical_body(physical_body)
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
