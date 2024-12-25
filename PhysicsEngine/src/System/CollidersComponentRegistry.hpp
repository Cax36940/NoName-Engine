#pragma once
#include <vector>

#include "Vector3.hpp"

class SphereCollider;
class Octree;

class CollidersComponentRegistry {
private:
	static std::vector<SphereCollider*> registry;

public:
	static void add(SphereCollider* collider);
	static void remove(SphereCollider* collider);
	static void check_collisions(Octree& visual_octree);
};