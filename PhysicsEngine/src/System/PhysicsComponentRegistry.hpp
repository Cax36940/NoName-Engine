#pragma once
#include <vector>
#include "../Component/Physics/PhysicsComponent.hpp"

class PhysicsComponentRegistry {
private:	
	static std::vector<PhysicsComponent*> registry;
public :
	static void add(PhysicsComponent* physics_component);
	static void remove(PhysicsComponent* physics_component);
	static void updatePhysics();
};