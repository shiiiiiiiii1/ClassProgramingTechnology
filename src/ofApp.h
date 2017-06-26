#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
		void setup();
		void update();
		void draw();
  
    ofImage myImage;
    static const int num_image_side = 4;
    static const int num_image_length = 3;
    int image_hight;
    int image_width;
};
