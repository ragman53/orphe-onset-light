#pragma once

#include "ofMain.h"
#include "OscManager.h"

#define HOST "localhost"
#define PORT_RECEIVER 1234
#define PORT_SENDER 4321

#define DEFAULT_LIGHT_NUM 0

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float mag;
    float magHSV;
    float magRGB;
    
    ofSoundPlayer beat;
    float * fftSmooth;
    int bands;
    
    float timeStamp;
    
    OscManager osc;
		
};
