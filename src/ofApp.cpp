#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowShape(229 * num_image_side, 172 * num_image_length);
  ofBackground(0, 0, 0);
  ofEnableAlphaBlending();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  myImage.load("HitachiTree.jpg");
  
  image_width = ofGetWidth() / num_image_side;
  image_hight = ofGetHeight() / num_image_length;
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i = 0; i < num_image_side; i++) {
    for (int q = 0; q < num_image_length; q++) {
      myImage.draw(i * image_width, q * image_hight, image_width, image_hight);
    }
  }
}
