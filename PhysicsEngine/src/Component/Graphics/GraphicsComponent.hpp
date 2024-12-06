#pragma once
#include "System/GraphicsComponentRegistry.hpp"

// Abstract class for Component that can be drawn on the screen
class GraphicsComponent {

protected:
	bool visible = true;
public:
	GraphicsComponent(){ GraphicsComponentRegistry::add(this); };
	GraphicsComponent(const GraphicsComponent&) { GraphicsComponentRegistry::add(this); };
	~GraphicsComponent(){ GraphicsComponentRegistry::remove(this); };
	
	void set_visible(bool visible_value) { visible = visible_value; };
	void toggle_visibility() { visible = !visible; }
	bool is_visible() const { return visible; };
	virtual void draw() = 0;

};