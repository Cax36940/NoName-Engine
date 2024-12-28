#include <cassert>

#include <GLFW/glfw3.h>

#include "AbstractMouse.hpp"
#include "Window.hpp"

AbstractMouse* AbstractMouse::mouse_instance = nullptr;

AbstractMouse::AbstractMouse(const Window& window) {
	assert(mouse_instance == nullptr && "Error: Attempt to create a second mouse instance");
	mouse_instance = this;
	SetAsCurrent(window);
}

AbstractMouse::~AbstractMouse() {
	mouse_instance = nullptr;
};

void AbstractMouse::GetPos(const Window& window, double& xpos, double& ypos)
{
	glfwGetCursorPos(window.window, &xpos, &ypos);
}

bool AbstractMouse::GetHover(const Window& window)
{
	return glfwGetWindowAttrib(window.window, GLFW_HOVERED);
}

void AbstractMouse::SetModeLockedMiddle(const Window& window)
{
	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void AbstractMouse::SetModeHidden(const Window& window)
{
	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void AbstractMouse::SetModeConfined(const Window& window)
{
	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
}

void AbstractMouse::SetModeNormal(const Window& window)
{
	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void AbstractMouse::SetAsCurrent(const Window& window)
{
	glfwSetCursorPosCallback(window.window, [](GLFWwindow* window, double xpos, double ypos) {AbstractMouse::mouse_instance->EventMouseMove(window, xpos, ypos); });
	glfwSetMouseButtonCallback(window.window, [](GLFWwindow* window, int button, int action, int mods) {AbstractMouse::mouse_instance->EventMouseButton(window, (MouseButton)button, (MouseAction)action, (MouseModFlag)mods); });
	glfwSetScrollCallback(window.window, [](GLFWwindow* window, double xoffset, double yoffset) {AbstractMouse::mouse_instance->EventMouseScroll(window, xoffset, yoffset); });
	glfwSetCursorEnterCallback(window.window, [](GLFWwindow* window, int entered) {AbstractMouse::mouse_instance->EventEnterWindow(window, entered); });
}
