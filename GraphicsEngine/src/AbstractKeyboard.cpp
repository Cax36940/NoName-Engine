#include <cassert>

#include <GLFW/glfw3.h>

#include "AbstractKeyboard.hpp"
#include "Window.hpp"

AbstractKeyboard* AbstractKeyboard::keyboard_instance = nullptr;

AbstractKeyboard::AbstractKeyboard(const Window& window)
{
	assert(keyboard_instance == nullptr && "Error: Attempt to create a second keyboard instance");
	keyboard_instance = this;
	SetAsCurrent(window);

	// Set KEYBOARD_MOD_CAPS_LOCK mod flag if Caps Lock is on
	// Set KEYBOARD_MOD_NUM_LOCK mod flag if Num Lock is on
	glfwSetInputMode(window.window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);
}

AbstractKeyboard::~AbstractKeyboard()
{
	keyboard_instance = nullptr;
}

int AbstractKeyboard::GetScancode(KeyboardKey key) const
{
	return glfwGetKeyScancode(key);
}

KeyboardAction AbstractKeyboard::GetState(const Window& window, KeyboardKey key) const
{
	return (KeyboardAction)glfwGetKey(window.window, key);
}

void AbstractKeyboard::SetAsCurrent(const Window& window)
{
	glfwSetKeyCallback(window.window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {AbstractKeyboard::keyboard_instance->EventKeyboardKey(window, (KeyboardKey)key, scancode, (KeyboardAction)action, mods); });
	glfwSetCharCallback(window.window, [](GLFWwindow* window, unsigned int utf32_char) {AbstractKeyboard::keyboard_instance->EventKeyboardChar(window, utf32_char); });
}
