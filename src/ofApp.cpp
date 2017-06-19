#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255, 255, 255);
  ofEnableAlphaBlending();
  ofSetCircleResolution(64);
  
  for (int i = 0; i < NUMBALL; i++) {
    location_x[i] = ofRandom(ofGetWidth());
    location_y[i] = ofRandom(ofGetHeight());
    speed_x[i] = ofRandom(-1.5, 1.5);
    speed_y[i] = ofRandom(-5.0, 5.0);
    radius[i] = ofRandom(10.0, 30.0);
  }
  
  gravity = 4.0;
  friction = 0.999;
}

//--------------------------------------------------------------
void ofApp::update(){
  for (int i = 0; i < NUMBALL; i++) {
    speed_y[i] = ofRandom(0, 4.0);
    location_y[i] += (speed_y[i] + gravity);
    speed_x[i] = ofRandom(-1.5, 1.5);
    location_x[i] += speed_x[i];
    if (location_y[i] > ofGetHeight()) {
      location_x[i] = ofRandom(ofGetWidth());
      location_y[i] = 0;
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(red, green, blue);
  for (int i = 0; i < NUMBALL; i++) {
    ofDrawCircle(location_x[i], location_y[i], radius[i]);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case 49:
      red = 255;
      green = 0;
      blue = 0;
      break;
    case 50:
      red = 200;
      green = 200;
      blue = 200;
      break;
  }
}
