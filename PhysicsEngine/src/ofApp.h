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

	// Scene Entities
	DefaultRigidBody cube;
	Arrow arrow;
	Origin origin;
	bool is_launched = false;
	DefaultParticle center_g_particle;

	RigidBodyType rb_types[4] = {
		CUBE,
		DODECAHEDRON,
		ICOSAHEDRON,
		OCTAHEDRON
	};
	int rb_types_index = 0;

	struct positionalForce {
		Vector3 pos;
		Vector3 force;
		Quaternion direction;

		positionalForce(const Vector3& p, const Vector3& f, const Quaternion& d) {
			pos = p;
			force = f;
			direction = d;
		}
	};
	positionalForce throw_force[5] = {
		positionalForce(Vector3(0, 0, 0), Vector3(0, 100, -100),	Quaternion(0.924, -0.383, 0, 0)),
		positionalForce(Vector3(1, 0, 0), Vector3(0, 100, -100),	Quaternion(0.924, -0.383, 0, 0)),
		positionalForce(Vector3(1, -1, 0), Vector3(0, 100, -100),	Quaternion(0.924, -0.383, 0, 0)),
		positionalForce(Vector3(0, 0, 0), Vector3(50, 100, -50),	Quaternion(0.924, -0.191, 0, -0.191)),
		positionalForce(Vector3(0, 0, 1), Vector3(-25, 100, -100),	Quaternion(0.924, -0.381, 0, 0.091))
	};
	int throw_force_index = 0;

	Vector3 centers_of_gravity[5] = {
		Vector3(0, 0, 0),
		Vector3(0, 1, 0),
		Vector3(1, 0, -1),
		Vector3(3, 0, 0),
		Vector3(0, 2, 0)
	};
	int centers_g_index = 0;
	
	void ResetRbAndThrowForce();
};