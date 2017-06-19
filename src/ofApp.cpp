#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0);
  ofSetFrameRate(60);
  ofSetCircleResolution(64);
  for (int i = 0; i < NUMBALL; i++) {
    radius[i] = ofRandom(10.0, 30.0);
    location_x[i] = ofRandom(0, ofGetWidth());
    location_y[i] = ofRandom(0, ofGetHeight());
    speed_x[i] = ofRandom(3.0, 7.0);
    speed_y[i] = ofRandom(3.0, 7.0);
    color[i] = i;
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  for (int i = 0; i < NUMBALL; i++) {
    location_x[i] += speed_x[i];
    location_y[i] += speed_y[i];
    if (location_x[i] < radius[i] || ofGetWidth()-radius[i] < location_x[i]) {
      speed_x[i] *= -1;
      color[i] = ofRandom(0, 5);
    }
    if (location_y[i] < radius[i] || ofGetHeight()-radius[i] < location_y[i]) {
      speed_y[i] *= -1;
      color[i] = ofRandom(0, 5);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i = 0; i < NUMBALL; i++) {
    switch (color[i]) {
      case 0:
        ofSetColor(255, 0, 0);
        break;
      case 1:
        ofSetColor(255, 255, 0);
        break;
      case 2:
        ofSetColor(0, 255, 0);
        break;
      case 3:
        ofSetColor(0, 255, 255);
        break;
      case 4:
        ofSetColor(0, 0, 255);
        break;
      case 5:
        ofSetColor(255, 0, 255);
        break;
    }
    ofDrawCircle(location_x[i], location_y[i], radius[i]);
  }
}
