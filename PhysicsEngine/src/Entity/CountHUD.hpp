#pragma once
#include "ofMain.h"
#include "Entity/GravityChar.hpp"
#include <vector>

class CountHUD
{
private:
	int x_pos;
	int y_pos;
	int value;
	ofTrueTypeFont* font;
	int text_length;

	std::vector<GravityChar> characters;

	void set_value(int value);

public:
	CountHUD() : x_pos(0), y_pos(0), value(0), font(nullptr) {};
	CountHUD(int x_pos, int y_pos, int value, ofTrueTypeFont* font) : x_pos(x_pos), y_pos(y_pos), value(-1), font(font) {
		characters.clear();
		set_value(value);
		text_length = strlen("Currently selected blob is composed of : ");
	};

	void update(float delta, int value);
	void draw();
};