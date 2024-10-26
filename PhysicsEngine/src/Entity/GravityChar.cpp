#include "GravityChar.hpp"
#include <iostream>

GravityChar::GravityChar(std::string c, float x_pos, float max_y_pos, float gravity_strength, ofTrueTypeFont* font)
	: c(c)
	, max_y_pos(max_y_pos)
	, physical_body(Particle(Vector3(x_pos, max_y_pos - 200, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 1))
	, gravity_strength(gravity_strength)
	, font(font)
{
}

void GravityChar::update(float delta)
{
	if (physical_body.get_position().y > max_y_pos) {
		physical_body.set_position(Vector3(physical_body.get_position().x, max_y_pos, physical_body.get_position().z));
		physical_body.set_velocity(Vector3(0, -1. * physical_body.get_velocity().y * 0.5, 0));
	}
	physical_body.add_force(Vector3(0, gravity_strength * physical_body.get_mass(), 0));
}

void GravityChar::draw()
{
	font->drawString(c, physical_body.get_position().x, physical_body.get_position().y);
}