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


public:
	CountHUD() = default;
	CountHUD(int x_pos, int y_pos, int value, ofTrueTypeFont* font) : x_pos(x_pos), y_pos(y_pos), value(-1), font(font) {
		characters.clear();
		set_value(value);
		text_length = strlen("Currently selected blob is composed of : ");
	};

	void set_value(int value);
	void draw();
};