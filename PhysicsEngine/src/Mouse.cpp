#include <iostream>

#include "Mouse.hpp"

Mouse::Mouse(const Window& window) : 
	AbstractMouse(window), x(0.0), y(0.0), pressed(false) 
{
}

void Mouse::EventMouseMove(const Window& window, double xpos, double ypos)
{
	x = xpos;
	y = ypos;
	std::cout << x << "    " << y << std::endl;
	// Rotation of the camera with the mouse
	if (pressed) {
		/*
		cam_orientation.y += (x - ofGetPreviousMouseX()) * rotation_speed; // yaw
		cam_orientation.x += (y - ofGetPreviousMouseY()) * rotation_speed; // pitch

		cam_orientation.x = ofClamp(cam_orientation.x, -90, 90);// avoid flip

		camera.setOrientation(glm::vec3(cam_orientation.x, cam_orientation.y, cam_orientation.z));
		*/
	}
}

void Mouse::EventMouseButton(const Window& window, MouseButton button, MouseAction action, MouseModFlag mods)
{
	if (button == MOUSE_BUTTON_LEFT) {
		if(action == MOUSE_ACTION_PRESSED) {
			pressed = true;
		}
		else if (action == MOUSE_ACTION_RELEASED) {
			pressed = false;
		}
	}
}

void Mouse::EventMouseScroll(const Window& window, double xoffset, double yoffset)
{
}

void Mouse::EventEnterWindow(const Window& window, bool entered)
{
}
