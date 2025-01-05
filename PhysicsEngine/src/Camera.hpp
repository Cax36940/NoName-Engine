#pragma once
#include "Matrix4.hpp"
#include "Vector3.hpp"

class Camera
{
private:
	Matrix4 view;
	Vector3 translation;
	constexpr static float rotation_speed = 0.015f;
	float x_angle = 0.0f;
	float y_angle = 0.0f;
	char dir_pressed;

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

	const Matrix4& get_view() const;

	void press_direction(Direction direction);
	void release_direction(Direction direction);

	void update_position();


private:
	void update_rotation();

};

