#pragma once
#include <vector>
#include "Component/Vector3.hpp"

class SphereCollider;
class Particle;

class CollidersComponentRegistry {
private:
	static std::vector<SphereCollider*> registry;

	struct Collision {
		Particle* particle;
		Vector3 delta_position;
		Vector3 delta_velocity;
	};

	static std::vector<Collision> collisions;

public:
	static void add(SphereCollider* collider);
	static void remove(SphereCollider* collider);
	static void check_collisions();
	static void solve_collisions();
};