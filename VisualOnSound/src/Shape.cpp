#include "Shape.h"



void Shape::setValues(float res_value, int x_position) {
	resolution = res_value;
	xPos = x_position;
}

void Shape::drawShape() {
	ofSetColor(245, 58, 135);
	ofFill();
	ofSetCircleResolution(resolution);
	//std::cout << resolution;
	ofDrawCircle(xPos, 600, 80);
}