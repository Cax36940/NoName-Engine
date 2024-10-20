#pragma once
#include <vector>
#include "Component/Vector3.hpp"
#include "Component/Particle.hpp"

class CollisionsRegistry {
private:
	struct Collision {
		Particle* particle;
		Vector3 delta_position;
		Vector3 delta_velocity;
	};

	static std::vector<Collision> registry;

public:
	static void add(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity);
	static void remove(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity);
	static void solve_collisions();
};