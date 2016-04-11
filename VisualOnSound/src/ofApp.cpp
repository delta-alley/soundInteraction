#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	int bufferSize = 256;
	micInput.assign(bufferSize, 0.0);
	soundStream.setup(this, 0, 1, 44100, bufferSize, 4);

	shapeConstruct = false;
	highInput = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	
	if (scaledVol > 0.1) {
		shapeConstruct = true;
	}
	if (shapeConstruct) {
		if (scaledVol > highInput) {
			highInput = scaledVol;
		}
		
		if (scaledVol < 0.1) {
			Shape shape;
			shape.setValues(highInput*30.0, rand() % 1024);
			shapeList.push_back(shape);
			highInput = 0.0;
			shapeConstruct = false;

			if (shapeList.size()>100) {
				shapeList.erase(shapeList.begin(), shapeList.begin() + 1);
			}
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(245, 58, 135);
	ofFill();
	ofSetCircleResolution(scaledVol* 30.0);
	ofDrawCircle(ofGetWidth()/2, 200, 80);
	
	for (int i = 0; i < shapeList.size(); i++) {
		shapeList[i].drawShape();
	}
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels) {
	float curVol = 0.0;
	int numCounted = 0;

	for (int i = 0; i < bufferSize; i++) {
		micInput[i] = input[i];
		curVol += micInput[i] * micInput[i];
		numCounted += 2;
	}
	curVol /= (float)numCounted;
	curVol = sqrt(curVol);

	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
}

//--------------------------------------------------------------
