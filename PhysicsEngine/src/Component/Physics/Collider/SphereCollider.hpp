#pragma once
#include "Component/Vector3.hpp"
#include "System/CollidersComponentRegistry.hpp"

class SphereCollider {
private:
	Vector3 position;
	float size;

public:
	SphereCollider() { CollidersComponentRegistry::add(this); };
	SphereCollider(const Vector3& pos, const float& size);
	~SphereCollider() { CollidersComponentRegistry::remove(this); };

	void set_position(const Vector3& pos);
	void set_size(const float& new_size);

	Vector3 get_position() const;
	float get_size() const;
};