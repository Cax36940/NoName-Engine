#pragma once
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	//Initialize different types of particles
	fireBall = FireBall(
		Vector3(0, 700, 0)
	);
	fireBall.set_body_size(25);
	fireBall.set_space(5);

	particle1 = TrailParticle(Vector3(0,700,0),Vector3(200,-150,0),Vector3(0,45,0),1);
	particle1.set_body_size(10);
	particle1.set_space(25);

	particle2 = TrailParticle(Vector3(0, 700, 0), Vector3(100, -150, 0), Vector3(0, 45, 0), 1);
	particle2.set_body_size(20);
	particle2.set_space(15);

	//Adding the particles to the list
    particles.push_back(particle1);
	particles.push_back(particle2);
	particles.push_back(fireBall);

	
}

//--------------------------------------------------------------
void ofApp::update(){

	if (isPlaying) {
		auto time = std::chrono::high_resolution_clock::now();
		auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count();
		particle.update(delta / 1000.);
		timeLastFrame = time;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	backgroundPicture.draw(0, 0, 1024, 768);
	myfont.drawString("Launch a missile with the space bar\nUse left and right arrow to change the missile", 30,40);
	
	particles[particlesIndex].drawSingleParticle();
	

	if (isPlaying) {
		particle.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	std::cout << particlesIndex<<endl;
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

	//Rereate the projectiles when hitting space key
	fireBall = FireBall(
		Vector3(0, 700, 0)
	);

	particle1 = TrailParticle(Vector3(0, 700, 0), Vector3(100, -150, 0), Vector3(0, 45, 0), 1);

	particle2 = TrailParticle(Vector3(0, 700, 0), Vector3(100, -150, 0), Vector3(0, 45, 0), 1);


	particle = particles[particlesIndex]; //update choice of missile

	timeLastFrame = std::chrono::high_resolution_clock::now();
	isPlaying = 1; //lauch the projectile when it's ready
}