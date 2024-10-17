#pragma once
#include <vector>
#include "Component/Vector3.hpp"

class SphereCollider;

class CollidersComponentRegistry {
private:
	static std::vector<SphereCollider*> registry;

	struct Collision {
		SphereCollider* collider1;
		SphereCollider* collider2;
		float collision_distance;
		Vector3 col1_to_col2;
	};

	static std::vector<Collision> collisions;

public:
	static void add(SphereCollider* collider);
	static void remove(SphereCollider* collider);
	static void check_collisions();
	static void solve_collisions();
};