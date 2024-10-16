#include <ofGraphics.h>
#include "SpringSprite.hpp"

void SpringSprite::set_width(const float& new_width) {
	width = new_width;
}

void SpringSprite::set_color(const float& r, const float& g, const float& b) {
	color = glm::vec3(r, g, b);
}

void SpringSprite::set_positions(const Vector3& pos1, const Vector3& pos2) {
	point1 = pos1;
	point2 = pos2;

}

void SpringSprite::draw()
{
	if (!visible) {
		return;
	}
	ofSetColor(color.r, color.g, color.b);
	ofSetLineWidth(width);
	ofDrawLine(Vector3::to_glm_vec3(point1), Vector3::to_glm_vec3(point2));
}
