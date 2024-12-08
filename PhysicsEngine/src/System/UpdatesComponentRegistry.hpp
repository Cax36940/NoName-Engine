#pragma once
#include <vector>

class UpdatesComponent;

class UpdatesComponentRegistry
{
private:

	static std::vector<UpdatesComponent*> registry;

public:
	static void add(UpdatesComponent* component);
	static void remove(UpdatesComponent* component);
	static void invert(UpdatesComponent* component1, UpdatesComponent* component2);
	static void clear();
	static void update_all(float delta);
};

