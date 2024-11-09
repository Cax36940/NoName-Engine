#include <ofGraphics.h>
#include <of3dGraphics.h>
#include "EyeSprite.hpp"

void EyeSprite::set_position(const Vector3& pos) {
	position = pos;
}


Vector3 EyeSprite::get_position() const
{
	return position;
}

void EyeSprite::draw()
{
	if (!visible) {
		return;
	}
	ofSetColor(255, 255, 255);
	ofDrawSphere(glm::vec3(position.x, position.y, position.z), 10);
	ofSetColor(0, 0, 0);
	ofDrawSphere(glm::vec3(position.x, position.y, position.z), 5);
}
