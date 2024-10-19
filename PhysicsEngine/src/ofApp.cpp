#pragma once
#include "ofApp.h"
#include "System/CollidersComponentRegistry.hpp"
#include "System/GraphicsComponentRegistry.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "System/PhysicsComponentRegistry.hpp"
#include "Entity/ParticleFactory.hpp"


#include "Entity/ParticleFactory.hpp"

//--------------------------------------------------------------
void ofApp::setup() {

	// Inititalize environment
	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	timeLastFrame = std::chrono::high_resolution_clock::now();

	mouse_x = 0;
	mouse_y = 0;
	drag_particle = nullptr;
	particle_list.reserve(20);

	// Initialize scene entities
	/*particle = ParticleFactory::createSimpleParticle(Vector3(WINDOW_WIDTH/2, 250, 0));
	particle2 = ParticleFactory::createSimpleParticle(Vector3(WINDOW_WIDTH / 2 + 50, 250, 0));

	particleA = ParticleFactory::createSimpleParticle(Vector3(WINDOW_WIDTH / 2 - 150, 250, 0));
	particleB = ParticleFactory::createSimpleParticle(Vector3(WINDOW_WIDTH / 2 - 100, 250, 0));

	spring = SimpleSpring(&particle.particle, 10, 100, Vector3(WINDOW_WIDTH / 2, 100, 0), 5, glm::vec3(0.5, 0.5, 0.5));
	spring2 = DampedSimpleSpring(&particle2.particle, 10, 1, 100, Vector3(WINDOW_WIDTH / 2 + 50, 100, 0), 5, glm::vec3(0.5, 0.5, 0.5));
	springAB = DoubleSpring(&particleA.particle, &particleB.particle, 1, 40, 5, glm::vec3(0.5, 0.5, 0.5));
	*/
	bob = Blob(Vector3(500, 500, 0), 20);

	gravity = GravityForce(10);
	mouse_pull_force = PullForce(10, Vector3(0, 0, 0));
	/*
	particle_list.push_back(&particle);
	particle_list.push_back(&particle2);
	particle_list.push_back(&particleA);
	particle_list.push_back(&particleB);*/


	for (DefaultParticle& part : bob.particles) {
		particle_list.push_back(&part);
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count() / 1000.; //durée de calcul d'une frame
	timeLastFrame = time;

	// Register forces from physics components
	PhysicsComponentRegistry::register_all_physics();

	// Checking collisions
	CollidersComponentRegistry::check_collisions();
	CollidersComponentRegistry::solve_collisions();

	// Applying forces
	/*ParticleForceRegistry::add(particle.get_physical_particle(), &gravity);
	ParticleForceRegistry::add(particle2.get_physical_particle(), &gravity);*/


	if (mouse_pressed && !drag_particle) {
		mouse_pull_force.set_position(Vector3(mouse_x, mouse_y, 0));
	}

	for (DefaultParticle& part : bob.particles) {
		ParticleForceRegistry::add(part.get_physical_particle(), &gravity);
		if (mouse_pressed && !drag_particle) {
			ParticleForceRegistry::add(part.get_physical_particle(), &mouse_pull_force);
		}
	}
	ParticleForceRegistry::update_forces(delta);


	// Update mouse control on particle
	if (drag_particle)
	{
		drag_particle->get_physical_particle()->clear_accum();
		drag_particle->get_physical_particle()->set_position(Vector3(mouse_x, mouse_y, 0));
		drag_particle->get_physical_particle()->set_velocity(Vector3(0, 0, 0));
	}

	// Updating every object
	/*particle.update(delta);
	particle2.update(delta);
	particleA.update(delta);
	particleB.update(delta);
	spring.update(delta);
	spring2.update(delta);
	springAB.update(delta);*/
	bob.update(delta);
	// Clear for next update
	ParticleForceRegistry::clear();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetupScreenOrtho(WINDOW_WIDTH, WINDOW_HEIGHT, -1000, 1000);
	ofSetColor(255);
	backgroundPicture.draw(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	GraphicsComponentRegistry::draw_all();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	static bool visible = false;
	visible = !visible;
	if (key == 'h') {
		bob.set_inside_visible(visible);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

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

	for (DefaultParticle* particle_it : particle_list) {

		const Vector3 pos_souris(x, y, 0);
		const Vector3& pos_particle = particle_it->particle.get_position();
		int rayon = particle_it->sprite.get_size();

		const Vector3 distance = pos_souris - pos_particle;
		if (Vector3::norm(distance) < rayon) {
			drag_particle = particle_it;
			return;
		}
	}
	drag_particle = nullptr;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouse_pressed = false;
	drag_particle = nullptr;
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
