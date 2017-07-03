#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
  
    ofImage Image1;
    ofImage Image2;
    ofImage Image3;
    ofPixels Pixels1;
    ofPixels Pixels2;
    ofPixels Pixels3;
    int image_width;
    int image_hight;
    float mixing_ratio;
};
