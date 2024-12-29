#include <cmath>

#include "Vector3.hpp"

#include "Camera.hpp"

void Camera::translate(const Vector3& vector)
{
	view.t += Vector4(vector, 0.0f);
}

void Camera::translate(float x, float y, float z)
{
	view.t.x = x;
	view.t.y = y;
	view.t.z = z;
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

	Vector4 tmp_translation = view.t;

	view = rotation_x * rotation_y;
	view.t = tmp_translation;
}

