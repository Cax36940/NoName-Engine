#pragma once
#include "ofApp.h"
#include "ParticleFactory.hpp"



//--------------------------------------------------------------
void ofApp::setup(){
	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);


}

//--------------------------------------------------------------
void ofApp::update(){
	
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count(); //durée de calcul d'une frame
	timeLastFrame = time;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetupScreenOrtho(WINDOW_WIDTH, WINDOW_HEIGHT, -1000, 1000);
	ofSetColor(255);
	backgroundPicture.draw(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

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

