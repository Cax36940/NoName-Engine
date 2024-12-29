#include "Camera.hpp"
#include "Mouse.hpp"

Mouse::Mouse(const Window& window, Camera& camera) :
	AbstractMouse(window),
	camera(camera)
{
}

void Mouse::EventMouseMove(const Window& window, double xpos, double ypos)
{
	previous_x = x;
	previous_y = y;
	x = xpos;
	y = ypos;

	// Rotation of the camera with the mouse
	if (pressed) {
		camera.rotate_xy(y - previous_y, x - previous_x); // Moving on the x axis make the y_axis rotate
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
