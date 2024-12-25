#pragma once
#include <vector>

#include "Vector3.hpp"
#include "Component/Particle.hpp"
#include "Component/RigidBody.hpp"

class CollisionsRegistry {
private:
	struct ParticleCollision {
		Particle* particle;
		Vector3 delta_position;
		Vector3 delta_velocity;
	};

	struct RigidBodyCollision {
		RigidBody* rigidbody;
		Vector3 delta_position;
		Vector3 impact_point;
		Vector3 impact_velocity;
	};

	static std::vector<ParticleCollision> particle_registry;
	static std::vector<RigidBodyCollision> rigidbody_registry;

public:
	static void add(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity);
	static void add(RigidBody* rigidbody, const Vector3& delta_position, const Vector3& impact_point, const Vector3& impact_velocity);
	static void remove(Particle* particle, const Vector3& delta_position, const Vector3& delta_velocity);
	static void solve_collisions();
};