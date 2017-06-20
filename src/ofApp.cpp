#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255, 255, 255);
  ofEnableAlphaBlending();
  ofSetCircleResolution(64);
  
  speed_x_random = 1.0;
  
  for (int i = 0; i < NUMBALL; i++) {
    location_x[i] = ofRandom(ofGetWidth());
    location_y[i] = ofRandom(ofGetHeight());
    speed_x[i] = ofRandom(-1.0*speed_x_random, speed_x_random);
    speed_y[i] = ofRandom(-5.0, 5.0);
    radius[i] = ofRandom(10.0, 30.0);
  }
  
  red = 50;
  green = 50;
  blue = 50;
  alpha = 50;

  gravity = 9.8;
  friction = 0.999;
}

//--------------------------------------------------------------
void ofApp::update(){
  for (int i = 0; i < NUMBALL; i++) {
    // ひらひら制御
    switch ( int(ofRandom(0, 100)) ) {
      case 0:
        if ( -0.5 < speed_x[i] || speed_x[i] < 0.5) {
          speed_x[i] *= -1.0;
        }
        break;
    }
    location_x[i] += speed_x[i];

    // 重力制御
    speed_y[i] = radius[i]/50.0 * gravity * friction;
    location_y[i] += speed_y[i];

    // 画面外制御
    if (location_y[i] > ofGetHeight()+radius[i]*2) {
      location_x[i] = ofRandom(ofGetWidth());
      location_y[i] = -2 * radius[i];
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(red, green, blue, alpha);
  for (int i = 0; i < NUMBALL; i++) {
    ofDrawCircle(location_x[i], location_y[i], radius[i]);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case 49:
      red = 247;
      green = 200;
      blue = 206;
      alpha = 254;
      break;
    case 50:
      red = 160;
      green = 192;
      blue = 224;
      alpha = 255;
      break;
  }
}
