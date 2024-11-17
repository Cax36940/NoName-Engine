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

	gravity = GravityForce(-2);

	// Setup Scene
	//cube = RigidBodyFactory::createRigidBody(CUBE, Vector3(0, -30, 30));
	//arrow = Arrow(Vector3(20, 0, 0), 3, Vector3(255, 255, 255), Quaternion(0.354, -0.146, -0.854, 0.354));

	ResetRbAndThrowForce();
	origin = Origin(1.0);
}

//--------------------------------------------------------------
void ofApp::update() {
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count() / 1000.; //durée de calcul d'une frame
	timeLastFrame = time;

	if (apply_force) {
		//Vector3 camera_facing_vector(-camera.getZAxis()); 
		//glm::vec3 screen_cube_position = camera.worldToCamera(Vector3::to_glm_vec3(cube.get_position()));
		//glm::vec3 cube_mouse_vector = glm::vec3(((float)mouse_x * 2 / WINDOW_WIDTH) - 1, 1 - ((float)mouse_y * 2 / WINDOW_HEIGHT), 0) - screen_cube_position;
		//Vector3 moment_arm(cube_mouse_vector.x * camera.getXAxis() + cube_mouse_vector.y * camera.getYAxis());
		//cube.add_force(1000 * Vector3::cross(moment_arm, camera_facing_vector));
		
		//cube.add_force(Vector3(2, 4, 0), Vector3(0, 10000, -10000));

		cube.add_force(throw_force[throw_force_index].pos, throw_force[throw_force_index].force);
	}

	if (is_launched) {
		center_g_particle.particle.set_position(cube.get_position());
	}

	// Register forces from physics components
	PhysicsComponentRegistry::register_all_physics();

	// Checking collisions
	//CollidersComponentRegistry::check_collisions();
	//CollisionsRegistry::solve_collisions();

	// Applying forces
	if (is_launched)
	{
		ParticleForceRegistry::add(cube.get_physical_particle(), &gravity);
	}
	ParticleForceRegistry::update_forces(delta);

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

	ofSetColor(255, 0, 0);
	ofFill();
	//ofDrawBox(20);

	GraphicsComponentRegistry::draw_all();

	// End rendering form the camera's perspective.
	camera.end();
	sun.disable();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ' && !is_launched) { // Space
		apply_force = true;
		is_launched = true;
	}

	if (key == 'a') {
		rb_types_index = (rb_types_index + 3) % 4;
		ResetRbAndThrowForce();
	}
	else if (key == 'e') {
		rb_types_index = (rb_types_index + 1) % 4;
		ResetRbAndThrowForce();
	}

	if (key == 'q') {
		throw_force_index = (throw_force_index + 4) % 5;
		ResetRbAndThrowForce();
	}
	else if (key == 'd') {
		throw_force_index = (throw_force_index + 1) % 5;
		ResetRbAndThrowForce();
	}

	if (key == 'w') {
		centers_g_index = (centers_g_index + 4) % 5;
		ResetRbAndThrowForce();
	}
	else if (key == 'c') {
		centers_g_index = (centers_g_index + 1) % 5;
		ResetRbAndThrowForce();
	}

	if (key == 'v') {
		cube.get_mesh()->toggle_visibility();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == ' ') { // Space
		apply_force = false;
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::ResetRbAndThrowForce()
{
	is_launched = false;
	cube = RigidBodyFactory::createRigidBody(rb_types[rb_types_index], Vector3(0, 0, 30), centers_of_gravity[centers_g_index]);
	arrow = Arrow(
		cube.get_position() + throw_force[throw_force_index].pos, 
		1, 
		Vector3(255, 255, 255), 
		throw_force[throw_force_index].direction
	);

	center_g_particle = DefaultParticle(
		Particle(centers_of_gravity[centers_g_index] + cube.get_position(), Vector3(), Vector3(), 1),
		Sphere(0.2, glm::vec3(0, 255, 0))
	);
}