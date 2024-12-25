#pragma once

class GLFWwindow;

class Window {
private :
	GLFWwindow* window;
	int status;

public :
	Window(int width, int height);
	bool failed();
	bool closed();
	void terminate();
	void update();
};