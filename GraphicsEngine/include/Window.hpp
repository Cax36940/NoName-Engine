#pragma once

struct GLFWwindow;

class Window {
private :
	friend class AbstractMouse;
	friend class AbstractKeyboard;

	GLFWwindow* window;
	int status;

	Window(GLFWwindow* window) : window(window), status(0) {};

public :
	Window(int width, int height);
	bool failed();
	bool closed();
	void terminate();
	void update();
};