#pragma once
#include "System/CollidersComponentRegistry.hpp"
#include "Component/Particle.hpp"

class Mesh;

class SphereCollider {
private:
	float size;

public:
	Particle* physical_body;
	Mesh* collision_mesh;

	SphereCollider() : size(0), physical_body(nullptr), collision_mesh(nullptr){ CollidersComponentRegistry::add(this); }

	SphereCollider(const SphereCollider& collider) :
		size(collider.get_size()), 
		physical_body(collider.physical_body),
		collision_mesh(collider.collision_mesh){
		CollidersComponentRegistry::add(this); 
	}
	SphereCollider& operator=(const SphereCollider& sc) {
		size = sc.get_size();
		physical_body = sc.physical_body;
		collision_mesh = sc.collision_mesh;
		return *this;
	};

	SphereCollider(const float& size, Particle* physical_body, Mesh* collision_mesh);
	~SphereCollider() { 
		CollidersComponentRegistry::remove(this); 
	};

	void set_size(const float& new_size);
	float get_size() const;
	Mesh* get_mesh_ptr() const;
};