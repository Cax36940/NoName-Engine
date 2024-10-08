#pragma once
#include <vector>

class SphereCollider;

class CollidersComponentRegistry {
private:
	static std::vector<SphereCollider*> registry;
public:
	static void add(SphereCollider* collider);
	static void remove(SphereCollider* collider);
	static void checkCollisions();
};