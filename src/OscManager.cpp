#include "OscManager.h"

void OscManager::setup(string host, int portSender)
{
    
    sender.setup(host, portSender);
    
    
}

void OscManager::update() {
    
}

void OscManager::triggerLightWithRGBColor(int LorRorBOTH,int lightNum, int r, int g, int b)
{
    ofxOscMessage m;
    
    if(LorRorBOTH==0){
        m.setAddress("/LEFT/triggerLightWithRGBColor");
    }else if(LorRorBOTH==1){
        m.setAddress("/RIGHT/triggerLightWithRGBColor");
    }else if(LorRorBOTH==2){
        m.setAddress("/BOTH/triggerLightWithRGBColor");
    }
    
    //light pattern
    m.addIntArg(lightNum);
    //light color
    m.addIntArg(r);
    m.addIntArg(g);
    m.addIntArg(b);
    
   
    sender.sendMessage(m);
}

void OscManager::setHSVColor(int LorRorBOTH,int lightNum, int h, int s, int b){
    ofxOscMessage m;
    
    if(LorRorBOTH==0){
        m.setAddress("/LEFT/setHSVColor");
    }else if(LorRorBOTH==1){
        m.setAddress("/RIGHT/setHSVColor");
    }else if(LorRorBOTH==2){
        m.setAddress("/BOTH/setHSVColor");
    }
    //light pattern
    m.addIntArg(lightNum);
    //light color
    m.addIntArg(h);
    m.addIntArg(s);
    m.addIntArg(b);
    
    sender.sendMessage(m);
}

void OscManager::setLightOn(int LorRorBOTH,int lightNum){
    ofxOscMessage m;
    
    m.setAddress("/BOTH/setLightOn");
    m.addIntArg(lightNum);
    
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void OscManager::setLightOff(int LorRorBOTH,int lightNum){
    ofxOscMessage m;
    
    m.setAddress("/BOTH/setLightOff");
    m.addIntArg(lightNum);
    
    sender.sendMessage(m);
}








