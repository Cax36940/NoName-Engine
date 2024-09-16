#include "Sphere.hpp"
#include <ofGraphics.h>

void Sphere::set_position(const Vector3& pos) {
	position = pos;
}

void Sphere::set_size(float new_size) {
	size = new_size;
}

void Sphere::set_color(float r, float g, float b) {
	color = glm::vec3(r, g, b);
}

void Sphere::draw()
{

	glm::vec3 pos = glm::vec3(position.x, position.y, position.z);
	ofSetColor(color.r, color.g, color.b);
	ofDrawSphere(pos, this->size);
}
