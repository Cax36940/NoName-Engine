#pragma once
#include "Matrix4.hpp"
#include "Transform.hpp"
#include "Vector3.hpp"

class Camera
{
private:
	Transform transform;
	float x_angle = 0.0f;
	float y_angle = 0.0f;
	char dir_pressed = 0;

public:

	static enum Direction {
		UP_DIR = 1,
		DOWN_DIR = 1 << 1,
		RIGHT_DIR = 1 << 2,
		LEFT_DIR = 1 << 3
	};

	Camera();

	void translate(const Vector3& vector);
	void translate(float x, float y, float z);

	void rotate_x(float angle);
	void rotate_y(float angle);
	void rotate_xy(float angle_x, float angle_y);

	Matrix4 get_view() const;
	Vector3 get_world_position() const;

	void press_direction(Direction direction);
	void release_direction(Direction direction);

	void update_position();


private:
	void update_rotation();

};

