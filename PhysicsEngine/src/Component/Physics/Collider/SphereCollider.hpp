#pragma once
#include "System/CollidersComponentRegistry.hpp"
#include "Component/Particle.hpp"

class SphereCollider {
private:
	float size;

public:
	Particle* physical_body;

	SphereCollider() : size(0), physical_body(nullptr) { CollidersComponentRegistry::add(this); }

	SphereCollider(const SphereCollider& collider) :
		size(collider.get_size())
		, physical_body(collider.physical_body) { 
		CollidersComponentRegistry::add(this); 
	}
	SphereCollider& operator=(const SphereCollider& sc) {
		size = sc.get_size();
		physical_body = sc.physical_body;
		return *this;
	};

	SphereCollider(const float& size, Particle* physical_body);
	~SphereCollider() { 
		CollidersComponentRegistry::remove(this); 
	};

	void set_size(const float& new_size);
	float get_size() const;
};