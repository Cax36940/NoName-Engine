#pragma once
#include "AbstractKeyboard.hpp"

class Camera;

class Keyboard : private AbstractKeyboard
{
public:
	Keyboard(const Window& window, Camera& camera);

private:
	Camera& camera;

	void EventKeyboardKey(const Window& window, KeyboardKey key, int scancode, KeyboardAction action, int mods) override;

};

