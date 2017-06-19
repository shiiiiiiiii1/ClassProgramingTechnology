#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
  
public:
		void setup();
		void update();
		void draw();
  
  static const int NUMBALL = 5;
  
  float radius[NUMBALL];
  float location_x[NUMBALL];
  float location_y[NUMBALL];
  float speed_x[NUMBALL];
  float speed_y[NUMBALL];
  int color[NUMBALL];
};
