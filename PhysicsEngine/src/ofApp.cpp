#pragma once

#include <iostream>
#include "ofApp.h"
#include "System/CollidersComponentRegistry.hpp"
#include "System/CollisionsRegistry.hpp"
#include "System/GraphicsComponentRegistry.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "System/PhysicsComponentRegistry.hpp"
#include "System/UpdatesComponentRegistry.hpp"
#include "Entity/RigidBodyFactory.hpp"


static float random_float_value(float min_value, float max_value) {
	float u = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // random in [0, 1]
	u = u * 2.0f - 1.0f; // random in [-1, 1]
	float dense_u = u*u*u; // More dense on the center
	return (max_value + min_value) / 2.0f + dense_u * (max_value - min_value) / 2.0f;
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofEnableDepthTest();
	ofSetBackgroundColor(ofColor(140, 200, 225));
	// Inititalize environment
	background_picture.load("images/bg_picture.png");
	myfont.load("calibri", 20);
	camera.setDistance(60);
	sun.setDirectional();
	glm::quat sunDir = glm::quat(0.354, -0.146, -0.854, 0.354);
	sun.setGlobalOrientation(sunDir);

	timeLastFrame = std::chrono::high_resolution_clock::now();

	mouse_x = 0;
	mouse_y = 0;

	// Setup Scene

	floor = RigidBodyFactory::createRigidBody(PLANE, Vector3(0, -100, 0));
	floor.set_apply_gravity(false);
	wall1 = RigidBodyFactory::createRigidBody(PLANE, Vector3(100, -100, 0));
	wall1.set_apply_gravity(false);
	wall1.rotate_z(PI/2);
	current_body_type = CUBE;

	cubes.reserve(1000);
	float min_value = -90.0;
	float max_value = 90.0;
	for (int i = 0; i < 10; i++) {
		float rand_x = random_float_value(min_value, max_value);
		float rand_y = random_float_value(min_value, max_value);
		float rand_z = random_float_value(min_value, max_value);
		cubes.emplace_back(Vector3(rand_x, rand_y, rand_z));
	}

	for (int i = 0; i < 0; i++) {
		cubes.emplace_back(Vector3(10, -99 + 2 * i, 10));
	}

	// first person camera
	cam_position = ofVec3f(0, -80, 50); // initial position
	cam_orientation = ofVec3f(0, 0, 0); // pitch, yaw, roll
	camera.disableMouseInput(); // disable default mouse movements from ofeasycam
	move_speed = 1.0f;
	rotation_speed = 0.15f;

	origin = Origin(1.0);
	octree_visible = true;
}

int frameCount = 0;
//--------------------------------------------------------------
void ofApp::update() {
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count() / 1000.; //durée de calcul d'une frame
	timeLastFrame = time;
	if (delta > 1) {
		delta = 1.0f / 60.0f; // Avoid simulation explosion when dragging the window
	};


	// Register forces from physics components
	PhysicsComponentRegistry::register_all_physics();

	// Checking collisions
	CollidersComponentRegistry::check_collisions(visual_octree);
	CollisionsRegistry::solve_collisions();

	// Applying forces
	ParticleForceRegistry::update_forces(delta);

	// Update of camera position
	moveCamera();

	// Updating every object
	UpdatesComponentRegistry::update_all(delta);

	// Clear for next update
	ParticleForceRegistry::clear();
}

//--------------------------------------------------------------
void ofApp::draw() {
	sun.enable();
	// Begin rendering from the camera's perspective.
	camera.begin();

	ofDisableSmoothing();
	ofSetColor(255, 0, 0);
	ofFill();

	if (octree_visible) {
		ofSetColor(224, 0, 174);
		visual_octree.draw_tree();
	}

	for (auto& cube : cubes) {
		// cube is visible only if facing camera
		glm::vec3 vector_to_cube = Vector3::to_glm_vec3(cube.get_position()) - camera.getGlobalPosition();
		cube.mesh.set_visible(glm::dot(camera.getLookAtDir(), vector_to_cube) > 0);
	}

	GraphicsComponentRegistry::draw_all();

	// End rendering form the camera's perspective.
	camera.end();
	sun.disable();


	ofSetColor(255);

	ofDrawBitmapString("H : " + std::string(octree_visible ? "Hide" : "Show") + " Octree", 10, 20);
	ofDrawBitmapString("A : Previous body", 10, 40);
	ofDrawBitmapString("E : Next body", 10, 60);
	ofDrawBitmapString("SPACE : Launch body (Current : " + body_type_string(current_body_type) + ")", 10, 80);
	ofDrawBitmapString("ARROWS : Move camera", 10, 100);
	ofDrawBitmapString("Mouse : Rotate camera", 10, 120);
	ofDrawBitmapString("G : Low collision Gravity (" + std::string(RigidBody::enable_low_collision_gravity ? "ENABLED" : "DISABLED") + ")", 10, 140);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == ' ') { // Space
		float launching_speed = 20.0f;
		DefaultRigidBody new_body = RigidBodyFactory::createRigidBody(current_body_type, camera.getPosition());
		new_body.rigid_body.set_velocity(camera.getLookAtDir().x * launching_speed, camera.getLookAtDir().y * launching_speed, camera.getLookAtDir().z * launching_speed);
		cubes.emplace_back(new_body);

	}

	if (key == 'h') { // Hide/Show octree
		octree_visible = !octree_visible;
	}

	if (key == 'a') { // Previous body
		current_body_type = (RigidBodyType)((int)current_body_type + 1);
		if (current_body_type == PARTICLE_TYPE_COUNT) {
			current_body_type = CUBE;
		}
	}

	if (key == 'e') { // Next body
		if (current_body_type != CUBE) {
			current_body_type = (RigidBodyType)((int)current_body_type - 1);
		}
		else {
			current_body_type = OCTAHEDRON;
		}
	}

	if (key == 'g') { // Next body
		static bool next_value = false;
		RigidBody::set_enable_low_collision_gravity(next_value);
		next_value = !next_value;
	}


	// Movements of the camera with arrows

	if (key == OF_KEY_UP) {
		dir_pressed |= UP_DIR;
	}

	if (key == OF_KEY_DOWN) {
		dir_pressed |= DOWN_DIR;
	}

	if (key == OF_KEY_RIGHT) {
		dir_pressed |= RIGHT_DIR;
	}

	if (key == OF_KEY_LEFT) {
		dir_pressed |= LEFT_DIR;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	if (key == OF_KEY_UP) {
		dir_pressed &= 0xFFFF ^ UP_DIR;
	}

	if (key == OF_KEY_DOWN) {
		dir_pressed &= 0xFFFF ^ DOWN_DIR;
	}

	if (key == OF_KEY_RIGHT) {
		dir_pressed &= 0xFFFF ^ RIGHT_DIR;
	}

	if (key == OF_KEY_LEFT) {
		dir_pressed &= 0xFFFF ^ LEFT_DIR;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	mouse_x = x;
	mouse_y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	mouse_x = x;
	mouse_y = y;

	// Rotation of the camera with the mouse

	cam_orientation.y += (x - ofGetPreviousMouseX()) * rotation_speed; // yaw
	cam_orientation.x += (y - ofGetPreviousMouseY()) * rotation_speed; // pitch

	cam_orientation.x = ofClamp(cam_orientation.x, -90, 90);// avoid flip

	camera.setOrientation(glm::vec3(cam_orientation.x, cam_orientation.y, cam_orientation.z));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	mouse_x = x;
	mouse_y = y;
	mouse_pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouse_pressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::moveCamera()
{
	ofVec3f camVelocity(0.0f, 0.0f, 0.0f);
	if (dir_pressed & UP_DIR) {
		camVelocity += camera.getLookAtDir() * move_speed;
	}

	if (dir_pressed & DOWN_DIR) {
		camVelocity -= camera.getLookAtDir() * move_speed;
	}

	if (dir_pressed & RIGHT_DIR) {
		camVelocity += camera.getSideDir() * move_speed;
	}

	if (dir_pressed & LEFT_DIR) {
		camVelocity -= camera.getSideDir() * move_speed;
	}

	cam_position += camVelocity;
	camera.setPosition(cam_position);
}

std::string ofApp::body_type_string(RigidBodyType type)
{
	switch (type) {
	case CUBE:
		return "CUBE";
	case DODECAHEDRON:
		return "DODECAHEDRON";
	case ICOSAHEDRON:
		return "ICOSAHEDRON";
	case OCTAHEDRON:
		return "OCTAHEDRON";
	//case TETRAHEDRON:
		//return "TETRAHEDRON";
	default:
		break;
	}
	return "UNKNOWN";
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
