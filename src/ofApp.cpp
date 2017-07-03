#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 0);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  
  Image1.load("Sakura1.jpg");
  Image2.load("Sakura2.jpg");
  Image3.load("Sakura1.jpg");
  
  image_width = (int)Image1.getWidth();
  image_hight = (int)Image1.getHeight();
  ofSetWindowShape(image_width * 2, image_hight * 2);

  // r,g,bの順番で値を格納していく
  Pixels1 = Image1.getPixels();
  Pixels2 = Image2.getPixels();
  Pixels3 = Image3.getPixels();

  mixing_ratio = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
  Image3.setFromPixels(Pixels3);
  
  //  画像Cのビットマップ情報を格納する
  if (mixing_ratio <= 1.0) {
    for (int i = 0; i < image_width; i ++) {
      for (int j = 0; j < image_hight; j ++) {
        int num = j * 3 * image_width + i * 3;
        Pixels3[num] = Pixels1[num] * (1 - mixing_ratio) + Pixels2[num] * mixing_ratio;
        Pixels3[num+1] = Pixels1[num+1] * (1 - mixing_ratio) + Pixels2[num+1] * mixing_ratio;
        Pixels3[num+2] = Pixels1[num+2] * (1 - mixing_ratio) + Pixels2[num+2] * mixing_ratio;
      }
    }
    mixing_ratio += 0.005;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  Image1.draw(0, 0);
  Image2.draw(0, image_hight);
  Image3.draw(image_width, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  mixing_ratio = 0.0;
}
