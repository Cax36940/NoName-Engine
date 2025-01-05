#include "Camera.hpp"
#include "Keyboard.hpp"

Keyboard::Keyboard(const Window& window, Camera& camera) :
	AbstractKeyboard(window),
	camera(camera)
{

}

void Keyboard::EventKeyboardKey(const Window& window, KeyboardKey key, int scancode, KeyboardAction action, int mods)
{
	/*if (key == ' ') { // Space
		float launching_speed = 20.0f;
		DefaultRigidBody new_body = RigidBodyFactory::createRigidBody(current_body_type, camera.getPosition());
		new_body.rigid_body.set_velocity(camera.getLookAtDir().x * launching_speed, camera.getLookAtDir().y * launching_speed, camera.getLookAtDir().z * launching_speed);
		cubes.emplace_back(new_body);

	}

	if (key == 'h') { // Hide/Show octree
		octree_visible = !octree_visible;
	}

	if (key == 'a') { // Previous body
		current_body_type = (RigidBodyType)((int)current_body_type + 1);
		if (current_body_type == PARTICLE_TYPE_COUNT) {
			current_body_type = CUBE;
		}
	}

	if (key == 'e') { // Next body
		if (current_body_type != CUBE) {
			current_body_type = (RigidBodyType)((int)current_body_type - 1);
		}
		else {
			current_body_type = OCTAHEDRON;
		}
	}

	if (key == 'g') { // Next body
		static bool next_value = false;
		RigidBody::set_enable_low_collision_gravity(next_value);
		next_value = !next_value;
	}

	*/
	// Movements of the camera with arrows

	if (action == KEYBOARD_ACTION_PRESSED) {
		if (key == KEYBOARD_KEY_UP) {
			camera.press_direction(Camera::Direction::UP_DIR);
		}

		if (key == KEYBOARD_KEY_DOWN) {
			camera.press_direction(Camera::Direction::DOWN_DIR);
		}

		if (key == KEYBOARD_KEY_RIGHT) {
			camera.press_direction(Camera::Direction::RIGHT_DIR);
		}

		if (key == KEYBOARD_KEY_LEFT) {
			camera.press_direction(Camera::Direction::LEFT_DIR);
		}
	}

	if (action == KEYBOARD_ACTION_RELEASED) {
		if (key == KEYBOARD_KEY_UP) {
			camera.release_direction(Camera::Direction::UP_DIR);
		}

		if (key == KEYBOARD_KEY_DOWN) {
			camera.release_direction(Camera::Direction::DOWN_DIR);
		}

		if (key == KEYBOARD_KEY_RIGHT) {
			camera.release_direction(Camera::Direction::RIGHT_DIR);
		}

		if (key == KEYBOARD_KEY_LEFT) {
			camera.release_direction(Camera::Direction::LEFT_DIR);
		}
	}


}
