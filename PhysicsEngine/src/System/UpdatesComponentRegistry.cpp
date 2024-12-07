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
