#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	particle = Particle(
		Vector3(0, 700, 0),
		Vector3(100, -150, 0),
		Vector3(0, 45, 0),
		1
	);
	timeLastFrame = std::chrono::high_resolution_clock::now();
}

//--------------------------------------------------------------
void ofApp::update(){
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count();
	particle.update(delta / 1000.);
	timeLastFrame = time;
}

//--------------------------------------------------------------
void ofApp::draw(){
	particle.draw();
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
