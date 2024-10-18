#pragma once
#include "Component/Vector3.hpp"
#include "System/CollidersComponentRegistry.hpp"
#include "Component/Particle.hpp"

class SphereCollider {
private:
	Vector3 position;
	float size;

public:
	Particle* physical_body;

	SphereCollider() : position(0,0,0), size(0), physical_body(nullptr) { CollidersComponentRegistry::add(this); }

	SphereCollider(const SphereCollider& collider) 
		: position(collider.get_position())
		, size(collider.get_size())
		, physical_body(collider.physical_body) { 
		CollidersComponentRegistry::add(this); 
	}
	SphereCollider& operator=(const SphereCollider& sc) {
		position = sc.get_position();
		size = sc.get_size();
		physical_body = sc.physical_body;
		return *this;
	};

	SphereCollider(const Vector3& pos, const float& size, Particle* physical_body);
	~SphereCollider() { 
		CollidersComponentRegistry::remove(this); 
	};

	void set_position(const Vector3& pos);
	void set_size(const float& new_size);

	Vector3 get_position() const;
	float get_size() const;
};