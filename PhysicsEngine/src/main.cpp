#include "ofMain.h"
#include "ofApp.h"

#include <iostream>

#include "Vector3.hpp"

//========================================================================
int main( ){

	Vector3 vector(1., 2., 3.);
	std::cout << "vector takes " << sizeof(vector) << " bytes in memory" << std::endl;

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
