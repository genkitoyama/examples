#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    _font.load("hiraginoKakugoProNW6.otf", 32);
    
    
    // this is our buffer to stroe the text data
    ofBuffer buffer = ofBufferFromFile("mountData.txt");
    
    if(buffer.size()) {
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
            
            string line = *it;
            
            //Split line into strings
            vector<string> words = ofSplitString(line, ",");
            
            //Store strings into a custom container
            if (words.size()>=2) {
                mount mountain;
                mountain.name = words[0];
                mountain.lat = ofToFloat(words[1]);
                mountain.lon = ofToFloat(words[2]);
                
                _mountains.push_back(mountain);
            }
            
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    _font.drawString(_mountains[count].name, 100, 100);
    _font.drawString(ofToString(_mountains[count].lat), 100, 200);
    _font.drawString(ofToString(_mountains[count].lon), 100, 300);
    
    if(ofGetFrameNum() > 0 && ofGetFrameNum() % 60 == 0)
    {
        count++;
        if(count > (int)_mountains.size()-1)
        {
            count = 0;
        }
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
