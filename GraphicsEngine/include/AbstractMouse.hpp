#pragma once

class Window;

enum MouseButton {
	MOUSE_LEFT = GLFW_MOUSE_BUTTON_LEFT,
	MOUSE_RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
	MOUSE_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE
};

enum MouseAction {
	RELEASED = GLFW_RELEASE,
	PRESSED = GLFW_PRESS,
	REPEATED = GLFW_REPEAT,
	UNKNOWN = GLFW_KEY_UNKNOWN
};

enum MouseModFlag{
	SHIFT = GLFW_MOD_SHIFT,
	CONSTROL = GLFW_MOD_CONTROL,
	ALT = GLFW_MOD_ALT,
	SUPER = GLFW_MOD_SUPER,
	CAPS_LOCK = GLFW_MOD_CAPS_LOCK,
	NUM_LOCK = GLFW_MOD_NUM_LOCK,
};

class AbstractMouse {
private :

	static AbstractMouse* mouse_instance;

protected :
	AbstractMouse(const Window& window);
	~AbstractMouse();

	virtual void EventMouseMove(const Window& window, double xpos, double ypos) = 0;

	virtual void EventMouseButton(const Window& window, MouseButton button, MouseAction action, MouseModFlag mods) = 0;
	
	virtual void EventMouseScroll(const Window& window, double xoffset, double yoffset) = 0;

	virtual void EventEnterWindow(const Window& window, bool entered) = 0;


	static void GetPos(const Window& window, double& xpos, double& ypos);

	static bool GetHover(const Window& window);

	static void SetModeLockedMiddle(const Window& window);

	static void SetModeHidden(const Window& window);

	static void SetModeConfined(const Window& window);

	static void SetModeNormal(const Window& window);


	static void SetAsCurrent(const Window& window);

};