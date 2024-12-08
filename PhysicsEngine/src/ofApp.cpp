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
	cube1 = RigidBodyFactory::createRigidBody(CUBE, Vector3(10, -95, 10));
	//cube2 = RigidBodyFactory::createRigidBody(CUBE, Vector3(100, -30, 30));

	//cube1.rigid_body.set_velocity(10, 0, 0);
	//cube2.rigid_body.set_velocity(-10, 0, 0);

	plane = RigidBodyFactory::createRigidBody(PLANE, Vector3(0, -100, 0));
	plane.set_apply_gravity(false);

	cubes.reserve(1000);
	float min_value = -127.0;
	float max_value = 127.0;
	for (int i = 0; i < 0; i++) {
		float rand_x = random_float_value(min_value, max_value);
		float rand_y = random_float_value(min_value, max_value);
		float rand_z = random_float_value(min_value, max_value);
		cubes.emplace_back(Vector3(rand_x, rand_y, rand_z));
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

//--------------------------------------------------------------
void ofApp::update() {
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count() / 1000.; //durée de calcul d'une frame
	timeLastFrame = time;
	if (delta > 1) {
		delta = 1.0f / 60.0f;
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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
	if (key == ' ') { // Space
		float cube_speed = 10.0f;
		DefaultRigidBody new_cube = RigidBodyFactory::createRigidBody(CUBE, camera.getPosition());
		new_cube.rigid_body.set_velocity(camera.getLookAtDir().x * cube_speed, camera.getLookAtDir().y * cube_speed, camera.getLookAtDir().z * cube_speed);
		cubes.emplace_back(new_cube);

	}

	if (key == 'h') { // Hide/Show octree
		octree_visible = !octree_visible;
	}

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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
