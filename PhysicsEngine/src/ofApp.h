#pragma once

#include "ofMain.h"
#include "Entity/DefaultParticle.hpp"
#include "Entity/SimpleSpring.hpp"
#include "Component/Physics/Force/GravityForce.hpp"
#include <chrono>

#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	 720


class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:

	bool time_init = false;
	std::chrono::steady_clock::time_point timeLastFrame;

	int mouse_x;
	int mouse_y;
	DefaultParticle* drag_particle;

	DefaultParticle p1;
	DefaultParticle p2;

	// Setup elements
	ofImage backgroundPicture;
	ofTrueTypeFont myfont;
};
