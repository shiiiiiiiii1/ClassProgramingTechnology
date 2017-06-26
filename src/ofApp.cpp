#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(225, 225, 225);
  ofEnableAlphaBlending();
  ofSetCircleResolution(64);
  
  mySoundA.load("RingA.wav");
  mySoundB.load("RingB.wav");
  mySoundA.setLoop(true);
  mySoundB.setLoop(true);
  mySoundA.play();
  mySoundB.play();
  soundA_volume = 0.5;
  soundB_volume = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){
  locationA[0] = ofGetWidth() / 3;
  locationA[1] = ofGetHeight() / 2;
  locationB[0] = ofGetWidth() / 3 * 2;
  locationB[1] = ofGetHeight() / 2;

  if (0.0 <= soundA_volume && soundA_volume <= 1.0) {
    radiusA = ofMap(soundA_volume, 0.0, 1.0, 50.0, 100.0);
    mySoundA.setVolume(soundA_volume);
  } else if (soundA_volume < 0.0) {
    soundA_volume = 0.0;
    radiusA = 50.0;
  } else {
    soundA_volume = 1.0;
    radiusA = 100.0;
  }

  if (0.0 <= soundB_volume && soundB_volume <= 1.0) {
    radiusB = ofMap(soundB_volume, 0.0, 1.0, 50.0, 100.0);
    mySoundB.setVolume(soundB_volume);
  } else if (soundB_volume < 0.0) {
    soundB_volume = 0.0;
    radiusB = 50.0;
  } else {
    soundB_volume = 1.0;
    radiusB = 100.0;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(25, 25, 255);
  ofDrawCircle(locationA[0], locationA[1], radiusA);
  ofSetColor(255, 200, 0);
  ofDrawCircle(locationB[0], locationB[1], radiusB);
}

//--------------------------------------------------------------
void ofApp:: mousePressed(int x, int y, int button){
  // sound A update
  if (locationA[0]-radiusA < x && x < locationA[0]+radiusA && locationA[1]-radiusA < y && y < locationA[1]+radiusA) {
    switch (button) {
      case 0:
        soundA_volume += 0.1;
        break;
      case 2:
        soundA_volume -= 0.1;
        break;
    }
  }

  // sound B update
  if (locationB[0]-radiusB < x && x < locationB[0]+radiusB && locationB[1]-radiusB < y && y < locationB[1]+radiusB) {
    switch (button) {
      case 0:
        soundB_volume += 0.1;
        break;
      case 2:
        soundB_volume -= 0.1;
        break;
    }
  }

}
