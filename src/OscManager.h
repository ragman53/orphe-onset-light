#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp;

class OscManager {

    
public:

    OscManager() = default;
    ~OscManager() = default;
    
    
    
    
    
    
    void setup(string host,  int portSender);
    void update();
    
    void triggerLightWithRGBColor(int LorRorBOTH,int lightNum, int r, int g, int b);
    void setHSVColor(int LorRorBOTH,int lightNum, int h, int s, int b);
    void setLightOn(int LorRorBOTH,int lightNum);
    void setLightOff(int LorRorBOTH, int lightNum);
    
    
    
    ofxOscSender sender;
};
