#pragma once
#include "ofApp.h"
#include "System/CollidersComponentRegistry.hpp"
#include "System/GraphicsComponentRegistry.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "System/PhysicsComponentRegistry.hpp"

#include "Entity/ParticleFactory.hpp"

//--------------------------------------------------------------
void ofApp::setup(){

	// Inititalize environment
	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	timeLastFrame = std::chrono::high_resolution_clock::now();

	mouse_x = 0;
	mouse_y = 0;
	drag_particle = nullptr;


	// Initialize scene entities
	particle = ParticleFactory::createParticle(
		ParticleType::STATIC, 
		Vector3(WINDOW_WIDTH/2, 200, 0), 
		Vector3(0, 0, 0));

	spring = SimpleSpring(&particle.particle, 10, 100, Vector3(WINDOW_WIDTH/2, 100, 0), 5, glm::vec3(0.5,0.5,0.5));

	gravity = GravityForce(10);
}

//--------------------------------------------------------------
void ofApp::update(){
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count() / 1000.; //durée de calcul d'une frame
	timeLastFrame = time;

	// Register forces from physics components
	PhysicsComponentRegistry::register_all_physics();

	// Checking collisions
	//CollidersComponentRegistry::checkCollisions();

	// Applying forces
	ParticleForceRegistry::add(particle.get_physical_particle(), &gravity);
	ParticleForceRegistry::update_forces(delta);

	// Update mouse control on particle
	if (drag_particle)
	{
		drag_particle->get_physical_particle()->clear_accum();
		drag_particle->get_physical_particle()->set_position(Vector3(mouse_x, mouse_y, 0));
		drag_particle->get_physical_particle()->set_velocity(Vector3(0, 0, 0));
	}

	// Updating every object
	particle.update(delta);
	spring.update(delta);

	// Clear for next update
	ParticleForceRegistry::clear();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetupScreenOrtho(WINDOW_WIDTH, WINDOW_HEIGHT, -1000, 1000);
	ofSetColor(255);
	backgroundPicture.draw(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	GraphicsComponentRegistry::draw_all();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	mouse_x = x;
	mouse_y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mouse_x = x;
	mouse_y = y;

	//Vérifier si je clique sur la particle (à généraliser après)
	const Vector3 pos_souris(x, y, 0);
	const Vector3& pos_particle = particle.particle.get_position();
	int rayon = particle.sprite.get_size();
	
	const Vector3 distance = pos_souris - pos_particle;
	if (Vector3::norm(distance) < rayon) {
		drag_particle = &particle;
	}	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	drag_particle = nullptr;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

