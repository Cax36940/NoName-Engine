#pragma once
//#include "ofMain.h" // TODO implement character display
#include "Component/Particle.hpp"
#include "Component/Physics/Force/GravityForce.hpp"
#include <string>

class GravityChar : public UpdatesComponent
{
private:
	std::string c;
	Particle physical_body;
	//ofTrueTypeFont* font;
	float gravity_strength;
	float max_y_pos;

public:
	GravityChar() = default;
	GravityChar(std::string c, float x_pos, float max_y_pos, float gravity_strength);//, ofTrueTypeFont* font);

	void update(float delta) override;
	void draw();
};