#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255, 255, 255);
  ofEnableAlphaBlending();
  ofSetCircleResolution(64);
  
  radius = 50.0;
  alpha = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(200, 0, 0, alpha);
  ofDrawCircle(location_x, location_y, radius);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  switch (button) {
    case 0:   // 左
      location_x = float(x);
      location_y = float(y);
      alpha = 150;
      break;
    case 1:   // ホイール
      break;
    case 2:   // 右
      if ( sqrtf((location_x-float(mouseX))*(location_x-float(mouseX)) + (location_y-float(mouseY))*(location_y-float(mouseY))) <= radius ) {
        alpha = 0;
      }
      break;
  }
};
