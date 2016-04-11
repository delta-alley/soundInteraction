#pragma once

#include "ofMain.h"
#include "Shape.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void audioIn(float * input, int bufferSize, int nChannels);

		vector <float> micInput;
		vector <Shape> shapeList;
		
		float smoothedVol;
		float scaledVol;

		float highInput;
		bool shapeConstruct;

		ofSoundStream soundStream;
};
