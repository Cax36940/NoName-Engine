#include <ofGraphics.h>
#include "Sphere.hpp"

void Sphere::set_position(const Vector3& pos) {
	position = pos;
}

void Sphere::set_size(const float& new_size) {
	size = new_size;
}

void Sphere::set_color(const float& r, const float& g, const float& b) {
	color = glm::vec3(r, g, b);
}

float Sphere::get_size()
{
	return this->size;
}

void Sphere::draw()
{
	if (!visible) {
		return;
	}
	ofSetColor(color.r, color.g, color.b);
	ofDrawSphere(glm::vec3(position.x, position.y, position.z), this->size);
}
