#pragma once
#include "ofApp.h"
#include "System/GraphicsComponentRegistry.hpp"
#include "System/PhysicsComponentRegistry.hpp"
#include "System/CollidersComponentRegistry.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "Entity/ParticleFactory.hpp"



//--------------------------------------------------------------
void ofApp::setup(){
	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	particle = ParticleFactory::createParticle(
		ParticleType::STATIC, 
		Vector3(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0), 
		Vector3(0, 0, 0));

	gravity = GravityForce(-0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count(); //durée de calcul d'une frame
	timeLastFrame = time;

	// Adding forces
	ParticleForceRegistry::add(particle.get_physical_particle(), &gravity);

	// Checking collisions
	//CollidersComponentRegistry::checkCollisions();

	// Applying forces
	ParticleForceRegistry::updateForces(delta);
	particle.get_physical_particle()->apply_forces_euler();

	// Updating every object
	particle.update(delta);

	// Clear for next update
	particle.get_physical_particle()->clear_accum();
	ParticleForceRegistry::clear();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetupScreenOrtho(WINDOW_WIDTH, WINDOW_HEIGHT, -1000, 1000);
	ofSetColor(255);
	backgroundPicture.draw(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	GraphicsComponentRegistry::drawAll();
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
	if (drag_particle) {
		particle.particle.set_position(Vector3(x, y, 0));
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//Vérifier si je clique sur la particle (à généraliser après)
	Vector3 pos_souris = Vector3(x, y, 0);
	Vector3 pos_particle = particle.particle.get_position();
	int rayon = particle.sprite.get_size();
	
	Vector3 distance = pos_souris - pos_particle;
	if (distance.norm(distance) < rayon) {
		drag_particle = true;
	}	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	drag_particle = false;
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

