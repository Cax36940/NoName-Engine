#include <ofMain.h>
#include "Spring.hpp"

void Spring::set_positions(const Vector3& pos_a, const Vector3& pos_b) {
	position_a = pos_a;
	position_b = pos_b;
}

void Spring::set_radius(const float& new_radius) {
	radius = new_radius;
}

void Spring::set_color(const float& r, const float& g, const float& b) {
	color = glm::vec3(r, g, b);
}

void Spring::draw()
{
	if (!visible) {
		return;
	}
	ofSetColor(color.r, color.g, color.b);

	Vector3 direction = position_b - position_a;
	float length = 10 * TWO_PI;

	Matrix3 pass_matrix = Matrix3::get_orthonormal_base(direction);
	Vector3 to_draw;
	ofPolyline line;
	float i = 0;
	while (i < length) {
		float e = Vector3::norm(direction) / length;
		float f = cos(i) * radius;
		float g = sin(i) * radius;

		to_draw = pass_matrix * Vector3(e, f, g);
		
		line.addVertex(ofVec3f(to_draw.x, to_draw.y, to_draw.z));
		i += 0.005 * HALF_PI * 0.5;
	}
	line.draw();
}