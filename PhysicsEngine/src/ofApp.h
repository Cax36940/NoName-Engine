#pragma once

#include "ofMain.h"
#include "Component/Physics/Force/GravityForce.hpp"
#include "Entity/RigidBody.hpp"
#include <chrono>

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	900


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

	std::chrono::steady_clock::time_point timeLastFrame;

	int mouse_x;
	int mouse_y;
	bool mouse_pressed;

	GravityForce gravity;

	// Setup elements
	ofImage backgroundPicture;
	ofTrueTypeFont myfont;
	ofEasyCam camera;
	ofLight sun;

	// Scene Entities
	RigidTetrahedron cube;
};