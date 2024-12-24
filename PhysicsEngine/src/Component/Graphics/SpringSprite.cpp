//#include <ofMain.h> // TODO : Redo display without of
#include "SpringSprite.hpp"

#define TWO_PI 2 * 3.141592653 // TODO : use namespace Maths

void SpringSprite::set_positions(const Vector3* pos_a, const Vector3* pos_b) {
	position_a = pos_a;
	position_b = pos_b;
}

void SpringSprite::set_radius(const float& new_radius) {
	radius = new_radius;
}

void SpringSprite::set_color(const float& r, const float& g, const float& b) {
	color = Vector3(r, g, b);
}

void SpringSprite::draw()
{
	if (!visible) {
		return;
	}
	//ofSetColor(color.r, color.g, color.b);

	const Vector3 direction = *position_b - *position_a;

	const float length = 10 * TWO_PI;

	const Matrix3 pass_matrix = Matrix3::get_orthonormal_base(direction);
	Vector3 to_draw;
	//ofPolyline line;
	const float elongate = Vector3::norm(direction) / length;
	float i = 0;

	while (i < length) {
		float e = elongate * i;
		float f = cos(i) * radius;
		float g = sin(i) * radius;

		to_draw = *position_a + pass_matrix * Vector3(e, f, g);
	
		//line.addVertex(ofVec3f(to_draw.x, to_draw.y, to_draw.z));
		//i += 0.05 * HALF_PI * 0.5;
	}
	
	//line.draw();
}