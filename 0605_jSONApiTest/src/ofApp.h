#pragma once


#include "ofMain.h"
#include "ofxJSON.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();
    
    void keyPressed(int key);
    
    void accessAPI(float lon, float lat);
    
    ofxJSONElement result;
    
    string _str;
    
};
