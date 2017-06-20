#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);

  static const int NUMBALL = 100;
  float location_x[NUMBALL];
  float location_y[NUMBALL];
  float speed_x[NUMBALL];
  float speed_y[NUMBALL];
  float radius[NUMBALL];

  int red, green, blue, alpha;
  float gravity;
  float friction;
  float speed_x_random;
};
