#include "CountHUD.hpp"

void CountHUD::set_value(int value)
{
	if (this->value == value) {
		return;
	}

	this->value = value;
	characters.clear();
	int offset = 0;
	for (int i = 1; i <= value; i *= 10) {
		std::string v = to_string((value / i) % (i * 10));
		characters.push_back(GravityChar(v, x_pos + text_length*11 - offset, y_pos - 1, 200, font));
		offset += 15;
	}
}

void CountHUD::update(float delta, int value)
{
	set_value(value);
	for (int i = 0; i < characters.size(); i++)
	{
		characters[i].update(delta);
	}
}

void CountHUD::draw()
{
	ofSetColor(255);

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i].draw();
	}
	font->drawString("Currently selected blob is composed of        particles", x_pos, y_pos);
}