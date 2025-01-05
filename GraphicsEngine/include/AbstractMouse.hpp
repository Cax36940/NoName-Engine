#pragma once

class Window;

enum MouseButton {
	MOUSE_BUTTON_LEFT = 0,    // GLFW_MOUSE_BUTTON_LEFT
	MOUSE_BUTTON_RIGHT = 1,   // GLFW_MOUSE_BUTTON_RIGHT
	MOUSE_BUTTON_MIDDLE = 2   // GLFW_MOUSE_BUTTON_MIDDLE
};

enum MouseAction {
	MOUSE_ACTION_RELEASED = 0,    // GLFW_RELEASE
	MOUSE_ACTION_PRESSED = 1,     // GLFW_PRESS
	MOUSE_ACTION_REPEATED = 2,    // GLFW_REPEAT
	MOUSE_ACTION_UNKNOWN = -1     // GLFW_KEY_UNKNOWN
};

enum MouseModFlag {
	MOUSE_MOD_SHIFT = 0x0001,      // GLFW_MOD_SHIFT
	MOUSE_MOD_CONSTROL = 0x0002,   // GLFW_MOD_CONTROL
	MOUSE_MOD_ALT = 0x0004,        // GLFW_MOD_ALT
	MOUSE_MOD_SUPER = 0x0008,      // GLFW_MOD_SUPER
	MOUSE_MOD_CAPS_LOCK = 0x0010,  // GLFW_MOD_CAPS_LOCK
	MOUSE_MOD_NUM_LOCK = 0x0020    // GLFW_MOD_NUM_LOCK
};

class AbstractMouse {
private :

	static AbstractMouse* mouse_instance;

protected :
	AbstractMouse(const Window& window);
	~AbstractMouse();

	AbstractMouse(const AbstractMouse&) = delete;
	AbstractMouse& operator=(const AbstractMouse&) = delete;
	AbstractMouse(AbstractMouse&&) = delete;
	AbstractMouse& operator=(AbstractMouse&&) = delete;

	virtual void EventMouseMove(const Window& window, double xpos, double ypos) {};

	// mods is an OR of several MouseModFlag
	virtual void EventMouseButton(const Window& window, MouseButton button, MouseAction action, int mods) {};
	
	virtual void EventMouseScroll(const Window& window, double xoffset, double yoffset) {};

	virtual void EventEnterWindow(const Window& window, bool entered) {};


	static void GetPos(const Window& window, double& xpos, double& ypos);

	static bool GetHover(const Window& window);

	static void SetModeLockedMiddle(const Window& window);

	static void SetModeHidden(const Window& window);

	static void SetModeConfined(const Window& window);

	static void SetModeNormal(const Window& window);


	static void SetAsCurrent(const Window& window);

};