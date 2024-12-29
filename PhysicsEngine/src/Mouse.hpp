#pragma once
#include "AbstractMouse.hpp"

class Camera;

class Mouse : private AbstractMouse {
public :
	Mouse(const Window& window, Camera& camera);

private :
	Camera& camera;

	double previous_x = 0.0;
	double previous_y = 0.0;

	double x = 0.0;
	double y = 0.0;
	bool pressed = false; // Is left button pressed

	void EventMouseMove(const Window& window, double xpos, double ypos) override;

	void EventMouseButton(const Window& window, MouseButton button, MouseAction action, MouseModFlag mods) override;

	void EventMouseScroll(const Window& window, double xoffset, double yoffset) override;

	void EventEnterWindow(const Window& window, bool entered) override;

};

