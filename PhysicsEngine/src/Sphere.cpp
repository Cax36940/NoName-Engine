#include "Sphere.hpp"

void Sphere::draw()
{
	glm::vec3 pos = glm::vec3(position.x, position.y, position.z);
	ofDrawSphere(pos, this->size);
}
