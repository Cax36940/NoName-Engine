#pragma once
#include <vector>

class GraphicsComponent;

class GraphicsComponentRegistry {
private:
	static std::vector<GraphicsComponent*> registry;
public:
	static void add(GraphicsComponent* graphics_component);
	static void remove(GraphicsComponent* graphics_component);
	static void draw_all();
};