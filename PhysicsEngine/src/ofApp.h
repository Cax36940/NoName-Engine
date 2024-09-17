#pragma once

#include "ofMain.h"
#include "TrailParticle.hpp"
#include <chrono>
#include "FireBall.hpp"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
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
	FireBall fireBall;
	TrailParticle particle1;
	TrailParticle particle2;
	TrailParticle particle;
	std::vector<TrailParticle> particles;
	bool isPlaying = 0;
	int particlesIndex=0;

	std::chrono::steady_clock::time_point timeLastFrame;

	ofImage backgroundPicture;

	ofTrueTypeFont myfont;
};
