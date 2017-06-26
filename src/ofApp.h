#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
  public:
		void setup();
		void update();
		void draw();
		
		void mousePressed(int x, int y, int button);

    ofSoundPlayer mySoundA;
    ofSoundPlayer mySoundB;
    float soundA_volume;
    float soundB_volume;
    float radiusA;
    float radiusB;
    float locationA[2];
    float locationB[2];
};
