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
	x_angle -= angle * rotation_speed;
	update_rotation();
}

void Camera::rotate_y(float angle)
{
	y_angle -= angle * rotation_speed;
	update_rotation();
}

void Camera::rotate_xy(float angle_x, float angle_y)
{
	x_angle -= angle_x * rotation_speed;
	y_angle -= angle_y * rotation_speed;
	update_rotation();
}

const Matrix4& Camera::get_view() const
{
	Matrix3 rotation = view.get_ortho_transform();
	rotation.in_place_transpose();
	
	Vector4 tmp_translate = -view.t;
	tmp_translate.t = 1.0f;

	return Matrix4(Vector4(rotation.x, 0.0f), Vector4(rotation.y, 0.0f), Vector4(rotation.z, 0.0f), tmp_translate);
}

void Camera::press_direction(Direction direction)
{
	dir_pressed |= direction;
}

void Camera::release_direction(Direction direction)
{
	dir_pressed &= 0xFFFF ^ direction;
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

	view =  rotation_y * rotation_x;
	view.t = Vector4(translation, 1.0f);
}

void Camera::update_position()
{
	if (!dir_pressed) {
		return;
	}

	const float move_speed = 0.01;
	Vector3 velocity(0.0f, 0.0f, 0.0f);
	if (dir_pressed & UP_DIR) {
		velocity += view.get_ortho_transform() * Vector3(0.0f, 0.0f, -1.0f) * move_speed;
	}

	if (dir_pressed & DOWN_DIR) {
		velocity -= view.get_ortho_transform() * Vector3(0.0f, 0.0f, -1.0f) * move_speed;
	}

	if (dir_pressed & RIGHT_DIR) {
		velocity += Vector3(1.0f, 0.0f, 0.0f) * move_speed;
	}

	if (dir_pressed & LEFT_DIR) {
		velocity -= view.get_ortho_transform() * Vector3(1.0f, 0.0f, 0.0f) * move_speed;
	}

	translation += velocity;
	view.t = Vector4(translation, 1.0f);
}