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
	static void clear();
	static void update_all(float delta);
};

