#pragma once
#include "System/CollidersComponentRegistry.hpp"
#include "Component/Particle.hpp"

class Mesh;
class RigidBody;

class SphereCollider {
private:
	float size;

public:
	Particle* physical_body;
	Mesh* collider_mesh;
	RigidBody* rigid_body;

	SphereCollider() : size(0), physical_body(nullptr), collider_mesh(nullptr), rigid_body(nullptr){ CollidersComponentRegistry::add(this); }

	SphereCollider(const SphereCollider& collider) :
		size(collider.get_size()), 
		physical_body(collider.physical_body),
		collider_mesh(collider.collider_mesh),
		rigid_body(collider.rigid_body){
		CollidersComponentRegistry::add(this); 
	}
	SphereCollider& operator=(const SphereCollider& sc) {
		size = sc.get_size();
		physical_body = sc.physical_body;
		collider_mesh = sc.collider_mesh;
		rigid_body = sc.rigid_body;
		return *this;
	};

	SphereCollider(const float& size, Particle* physical_body, Mesh* collider_mesh, RigidBody* rigid_body);
	~SphereCollider() { 
		CollidersComponentRegistry::remove(this); 
	};

	void set_size(const float& new_size);
	float get_size() const;
	Mesh* get_mesh_ptr() const;
	RigidBody* get_rigibody_ptr() const;
};