#include "ofApp.h"


void ofApp::setup()
{
    _str = "";
    accessAPI(ofRandom(136.7, 140), ofRandom(35.7, 36.7));
}

void ofApp::accessAPI(float lon, float lat)
{
    string url = "http://cyberjapandata2.gsi.go.jp/general/dem/scripts/getelevation.php?";
    
    float longitute = lon;
    float latitude = lat;
    
    url += "lon="+ofToString(longitute,6)+"&lat="+ofToString(latitude,6)+"&outtype=JSON";
    
//    cout << url << endl;
    
    // Now parse the JSON
    bool parsingSuccessful = result.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << result.getRawString();
        _str += ofToString(result["elevation"].asFloat());
        _str += "\n";
    }
    else
    {
        ofLogNotice("ofApp::setup")  << "Failed to parse JSON" << endl;
    }

}

void ofApp::draw()
{
    ofBackground(0);
    
    // See this page for all of the ways to access data in a Json::Value
    // http://open-source-parsers.github.io/jsoncpp-docs/doxygen/class_json_1_1_value.html
    
    ofSetHexColor(0x00FF00);
    
//    ofDrawBitmapString(result["elevation"].asFloat(), 20,20);
//    ofDrawBitmapString(result["hsrc"].asString(), 20, 40);
    
    ofDrawBitmapString(_str, 10, 10);
    
//    if (result.isMember("elevation"))
//    {
//        ofDrawBitmapString(result.getRawString(), 10, 14);
//    }
//    else if (result.isArray())
//    {
//        const Json::Value& trends = result[0]["trends"];
//        
//        for (Json::ArrayIndex i = 0; i < trends.size(); ++i)
//        {
//            std::string message = trends[i]["query"].asString();
//            ofDrawBitmapString(message, 10, 40*i+40);
//        }
//    }
}

void ofApp::keyPressed(int key){
    if(key == 'c')
    {
        _str = "";
        return;
    }
    
    if(key != OF_KEY_ESC)
    {
        for(int i=0; i<10; i++)
        {
            accessAPI(ofRandom(136.7, 140), ofRandom(35.7, 36.7));
        }
    }
    
}
