#include <iostream>

#include "UpdatesComponentRegistry.hpp"
#include "Component/UpdatesComponent.hpp"

std::vector<UpdatesComponent *> UpdatesComponentRegistry::registry;

void UpdatesComponentRegistry::add(UpdatesComponent* component)
{
	registry.push_back(component);
}

void UpdatesComponentRegistry::remove(UpdatesComponent* component)
{
	int to_delete = -1;
	for (int i = 0; i < registry.size(); i++) {
		if (registry[i] == component)
		{
			to_delete = i;
		}
	}
	if (to_delete != -1) {
		registry.erase(registry.begin() + to_delete);
	}
}

void UpdatesComponentRegistry::invert(UpdatesComponent* component1, UpdatesComponent* component2)
{
	int index1 = -1;
	int index2 = -1;
	for (int i = 0; i < registry.size(); i++) {
		if (registry[i] == component1) {
			index1 = i;
		}
		if (registry[i] == component2) {
			index2 = i;
		}
	}
	if (index1 == -1 || index2 == -1) {
		std::cerr << "[ERROR] Invalid inversion in " << __FILE__ << " : " << __FUNCTION__ << "(line:" << __LINE__ << ")" << std::endl;
		return;
	}
	std::swap(registry[index1], registry[index2]);
}

void UpdatesComponentRegistry::clear()
{
	registry.clear();
}

void UpdatesComponentRegistry::update_all(float delta)
{
	if (delta == 0.0f) {
		return;
	}
	for (UpdatesComponent* component : registry) {
		component->update(delta);
	}
}
