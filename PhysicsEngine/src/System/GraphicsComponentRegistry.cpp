#include "Component/Graphics/GraphicsComponent.hpp"
#include "GraphicsComponentRegistry.hpp"

std::vector<GraphicsComponent*> GraphicsComponentRegistry::registry;

void GraphicsComponentRegistry::add(GraphicsComponent* graphics_component)
{
	registry.push_back(graphics_component);
}

void GraphicsComponentRegistry::remove(GraphicsComponent* graphics_component)
{
	for (auto i = registry.begin(); i != registry.end(); i++) {
		if (*i == graphics_component) {
			registry.erase(i);
			break;
		}
	}
}

void GraphicsComponentRegistry::draw_all()
{
	for (GraphicsComponent* graphics_component : registry) {
		graphics_component->draw();
	}
}