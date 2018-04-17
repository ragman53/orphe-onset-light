#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    osc.setup(HOST, PORT_SENDER);
    beat.loadSound("track_1.mp3");
    
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    
    beat.setLoop(true);
    beat.setVolume(0.2);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(bands);
    
    mag=ofMap(value[0]*10, 0, 1, 0, 1,true);
    magHSV=ofMap(value[0]*10, 0, 1, 0, 100,true);
    magRGB=ofMap(value[0]*10, 0, 1, 0, 255,true);
    
    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.99f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
        
        
    }
    float elapsedTime = ofGetElapsedTimef() - timeStamp;
    if (elapsedTime > 0.1) {
        osc.setLightOn(2, DEFAULT_LIGHT_NUM);
        osc.setHSVColor(2, DEFAULT_LIGHT_NUM, magRGB, 255, magHSV);
        timeStamp = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 100);
    for (int i = 0; i < bands; i++) {
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*300));
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            beat.play();
            break;
        case '2':
            beat.stop();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
