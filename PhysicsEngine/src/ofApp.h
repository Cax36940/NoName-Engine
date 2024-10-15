#pragma once

#include "ofMain.h"
#include "Entity/DefaultParticle.hpp"
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

	std::chrono::steady_clock::time_point timeLastFrame;
	bool isPlaying = false;

	bool drag_particle = false;

	DefaultParticle particle;

	// Setup elements
	ofImage backgroundPicture;
	ofTrueTypeFont myfont;
};
