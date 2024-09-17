#pragma once
#include "ofApp.h"
#include "ParticleFactory.hpp"

#define GRAVITY_VECTOR Vector3(0,45,0)

//--------------------------------------------------------------
void ofApp::setup(){

	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	// Reserve space for the particles
	particles.reserve(PARTICLE_TYPE_COUNT);

	// Adding one particle of each type to the list
	for (int i = 0; i < PARTICLE_TYPE_COUNT; i++) {
		particles.push_back(ParticleFactory::createParticle((ParticleType)i, Vector3(WINDOW_WIDTH - 50, 50, 0), Vector3(0, 0, 0)));
	}

	timeLastFrame = std::chrono::high_resolution_clock::now();
}

//--------------------------------------------------------------
void ofApp::update(){

	if (isPlaying) {
		auto time = std::chrono::high_resolution_clock::now();
		auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count();
		timeLastFrame = time;

		trail_particle.update(delta / 1000.);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	backgroundPicture.draw(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	ofSetColor(255);
	myfont.drawString("Launch a missile with the space bar\nUse left and right arrow to change the missile", 30,40);
	
	// Draw corner box
	ofDrawRectangle(WINDOW_WIDTH - 100,   0,   5, 100);
	ofDrawRectangle(WINDOW_WIDTH - 100,   0, 100,   5);
	ofDrawRectangle(WINDOW_WIDTH - 100, 100, 100,   5);
	ofDrawRectangle(WINDOW_WIDTH -   5,   0,   5, 100);

	// Start point
	ofDrawRectangle(45, WINDOW_HEIGHT - 45, 10, 10);

	particles[particlesIndex].draw();

	if (isPlaying) {
		trail_particle.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// Space key to restart the game
	if (key == ' ') {
		if (!isPlaying) {
			launchNewParticle();
		}
		else {
			isPlaying = !isPlaying;
		}
	}
	// Arrows to change the type of projectile
	else if (key == OF_KEY_RIGHT) {
		if (particlesIndex < particles.size()-1) {
			particlesIndex+=1;
		}
		else {
			particlesIndex=0;
		}
	}
	else if (key == OF_KEY_LEFT) {
		if (particlesIndex > 0) {
			particlesIndex-=1;
		}
		else {
			particlesIndex = particles.size()-1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

void ofApp::launchNewParticle() {

	trail_particle = TrailParticle(ParticleFactory::createParticle((ParticleType)particlesIndex, Vector3(50, WINDOW_HEIGHT - 50, 0), GRAVITY_VECTOR));

	timeLastFrame = std::chrono::high_resolution_clock::now();
	isPlaying = true; //lauch the projectile when it's ready
}