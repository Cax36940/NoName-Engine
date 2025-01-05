#include <cmath>

#include "Camera.hpp"

#define ROTATION_SPEED 0.010f
#define MOVE_SPEED 0.10f

Camera::Camera() : transform()
{
	update_rotation();
}

void Camera::translate(const Vector3& vector)
{
	transform.translation += vector;
	update_rotation();
}

void Camera::translate(float x, float y, float z)
{
	transform.translation.x = x;
	transform.translation.y = y;
	transform.translation.z = z;
	update_rotation();
}

void Camera::rotate_x(float angle)
{
	x_angle -= angle * ROTATION_SPEED;
	update_rotation();
}

void Camera::rotate_y(float angle)
{
	y_angle -= angle * ROTATION_SPEED;
	update_rotation();
}

void Camera::rotate_xy(float angle_x, float angle_y)
{
	x_angle -= angle_x * ROTATION_SPEED;
	y_angle -= angle_y * ROTATION_SPEED;
	update_rotation();
}

Matrix4 Camera::get_view() const
{
	Matrix3 rotation = transform.rotation;
	rotation.in_place_transpose();
	
	Vector3 tmp_translation = rotation * transform.translation;

	return Matrix4(Transform(rotation, -tmp_translation));
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
	Matrix3 rotation_x;
	Matrix3 rotation_y;

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

	transform.rotation =  rotation_y * rotation_x;
}

void Camera::update_position()
{
	if (!dir_pressed) {
		return;
	}

	Vector3 velocity(0.0f, 0.0f, 0.0f);
	if (dir_pressed & UP_DIR) {
		velocity += -transform.rotation.z;
	}

	if (dir_pressed & DOWN_DIR) {
		velocity -= -transform.rotation.z;
	}

	if (dir_pressed & RIGHT_DIR) {
		velocity += transform.rotation.x;
	}

	if (dir_pressed & LEFT_DIR) {
		velocity -= transform.rotation.x;
	}

	transform.translation += velocity * MOVE_SPEED;
}