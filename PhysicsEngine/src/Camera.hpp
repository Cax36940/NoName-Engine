#pragma once
#include "Matrix4.hpp"

struct Vector3;

class Camera
{
private:
	Matrix4 view;

	constexpr static float rotation_speed = 0.015f;
	float x_angle = 0.0f;
	float y_angle = 0.0f;

public:

	void translate(const Vector3& vector);
	void translate(float x, float y, float z);

	void rotate_x(float angle);
	void rotate_y(float angle);
	void rotate_xy(float angle_x, float angle_y);

	const Matrix4& get_view() const;

private:
	void update_rotation();

};

