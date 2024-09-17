#pragma once

#include "ofMain.h"
#include "TrailParticle.hpp"
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
	void launchNewParticle();
	void gotMessage(ofMessage msg);

private:

	TrailParticle trail_particle;
	std::vector<DefaultParticle> particles;
	bool isPlaying = false;
	int particlesIndex = 0;

	std::chrono::steady_clock::time_point timeLastFrame;

	ofImage backgroundPicture;

	ofTrueTypeFont myfont;
};
