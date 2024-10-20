#pragma once

#include "ofMain.h"
#include "Entity/Blob.hpp"
#include "Entity/DefaultParticle.hpp"
#include "Entity/DoubleSpring.hpp"
#include "Entity/SimpleSpring.hpp"
#include "Entity/DampedSimpleSpring.hpp"
#include "Component/Physics/Force/GravityForce.hpp"
#include "Component/Physics/Force/PullForce.hpp"
#include "Entity/CountHUD.hpp"
#include <chrono>

#define WINDOW_WIDTH	2000
#define WINDOW_HEIGHT	1000


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
	DefaultParticle* drag_particle;
	std::vector<DefaultParticle*> particle_list;
	int current_selected_blob;
	int second_selected_blob;
	int nb_of_particles_in_blob;

	/*DefaultParticle particle;
	DefaultParticle particle2;
	DefaultParticle particleA;
	DefaultParticle particleB;

	SimpleSpring spring;
	DampedSimpleSpring spring2;
	DoubleSpring springAB;*/

	std::vector<Blob> blobs;

	CountHUD blob_size_counter;

	GravityForce gravity;
	PullForce mouse_pull_force;


	// Setup elements
	ofImage backgroundPicture;
	ofTrueTypeFont myfont;

};