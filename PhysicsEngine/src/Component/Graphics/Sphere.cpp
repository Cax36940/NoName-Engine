//#include <ofGraphics.h> // TODO : Redo display without of
//#include <of3dGraphics.h>
#include "Sphere.hpp"

void Sphere::set_position(const Vector3* pos) {
	position = pos;
}

void Sphere::set_size(const float& new_size) {
	size = new_size;
}

void Sphere::set_color(const float& r, const float& g, const float& b) {
	color = Vector3(r, g, b);
}

Vector3 Sphere::get_position() const
{
	return *position;
}

float Sphere::get_size() const
{
	return size;
}

void Sphere::draw()
{
	if (!visible) {
		return;
	}
	//ofSetColor(color.r, color.g, color.b);
	//ofDrawSphere(glm::vec3(position->x, position->y, position->z), size);
}
