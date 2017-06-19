#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
  public:
		void setup();
		void update();
		void draw();
		
		void mousePressed(int x, int y, int button);
  
    float location_x, location_y;
    float radius;
    int alpha;
};
