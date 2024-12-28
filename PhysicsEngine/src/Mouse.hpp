#pragma once
#include "AbstractMouse.hpp"

class Mouse : private AbstractMouse {
public :
	Mouse(const Window& window);

private :
	double x;
	double y;
	bool pressed; // Is left button pressed

	void EventMouseMove(const Window& window, double xpos, double ypos) override;

	void EventMouseButton(const Window& window, MouseButton button, MouseAction action, MouseModFlag mods) override;

	void EventMouseScroll(const Window& window, double xoffset, double yoffset) override;

	void EventEnterWindow(const Window& window, bool entered) override;

};

