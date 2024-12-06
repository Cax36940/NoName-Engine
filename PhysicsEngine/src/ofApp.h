#pragma once

#include "ofMain.h"
#include "Component/Physics/Force/GravityForce.hpp"
#include "Entity/DefaultRigidBody.hpp"
#include "Entity/Origin.hpp"
#include "Entity/RigidBodyFactory.hpp"
#include "Entity/TrailParticle.hpp"
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
	bool apply_force;
	GravityForce gravity;

	// Setup elements
	ofImage background_picture;
	ofTrueTypeFont myfont;
	ofEasyCam camera;
	ofLight sun;

	ofVec3f  cam_position;
	ofVec3f  cam_orientation;
	float move_speed;
	float rotation_speed;
	void moveCamera();

	// Inputs
	enum Input {
		UP_DIR = 1,
		DOWN_DIR = 1 << 1,
		RIGHT_DIR = 1 << 2,
		LEFT_DIR = 1 << 3
	};
	char dir_pressed;

	// Scene Entities
	Origin origin;
	DefaultRigidBody cube;
	DefaultRigidBody cube2;


	RigidBodyType rb_types[4] = {
		CUBE,
		DODECAHEDRON,
		ICOSAHEDRON,
		OCTAHEDRON
	};

};