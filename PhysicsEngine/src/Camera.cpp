#include <cmath>

#include "Camera.hpp"

Camera::Camera() : translation(0.0f, 0.0f, 0.0f)
{
	update_rotation();
}

void Camera::translate(const Vector3& vector)
{
	translation += vector;
	update_rotation();
}

void Camera::translate(float x, float y, float z)
{
	translation.x = x;
	translation.y = y;
	translation.z = z;
	update_rotation();
}

void Camera::rotate_x(float angle)
{
	x_angle += angle * rotation_speed;
	update_rotation();
}

void Camera::rotate_y(float angle)
{
	y_angle += angle * rotation_speed;
	update_rotation();
}

void Camera::rotate_xy(float angle_x, float angle_y)
{
	x_angle += angle_x * rotation_speed;
	y_angle += angle_y * rotation_speed;
	update_rotation();
}

const Matrix4& Camera::get_view() const
{
	return view;
}

void Camera::update_rotation()
{
	Matrix4 rotation_x;
	Matrix4 rotation_y;

	float sin_x = sinf(x_angle);
	float cos_x = cosf(x_angle);
	float sin_y = sinf(y_angle);
	float cos_y = cosf(y_angle);

	rotation_x.y.y = cos_x;
	rotation_x.y.z = sin_x;
	rotation_x.z.y = -sin_x;
	rotation_x.z.z = cos_x;

	rotation_y.x.x = cos_y;
	rotation_y.x.z = -sin_y;
	rotation_y.z.x = sin_y;
	rotation_y.z.z = cos_y;

	Matrix4 translation_matrix;
	translation_matrix.t = Vector4(translation, 1.0f);

	view = rotation_x * rotation_y * translation_matrix;
}

