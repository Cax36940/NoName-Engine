#pragma once
#include "ofApp.h"
#include "System/GraphicsComponentRegistry.hpp"
#include "System/PhysicsComponentRegistry.hpp"
#include "Entity/ParticleFactory.hpp"



//--------------------------------------------------------------
void ofApp::setup(){
	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	particle = ParticleFactory::createParticle(
		ParticleType::STATIC, 
		Vector3(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0), 
		Vector3(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
	
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count(); //durée de calcul d'une frame
	timeLastFrame = time;

	p1.update(delta);
	p2.update(delta);
	CollidersComponentRegistry::checkCollisions();
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

