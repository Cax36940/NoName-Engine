#pragma once
#include <vector>

class PhysicsComponent;

class PhysicsComponentRegistry {
private:	
	static std::vector<PhysicsComponent*> registry;
public :
	static void add(PhysicsComponent* physics_component);
	static void remove(PhysicsComponent* physics_component);
	static void register_all_physics();
};