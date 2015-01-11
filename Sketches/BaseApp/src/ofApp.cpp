#include "ofApp.h"

#include "ofxSuperLog.h"
#include "ofxTimeMeasurements.h"
#include "ofxRemoteUIVars.h"

//--------------------------------------------------------------
// callback function for ofxRemoteUI actions
bool bRecalcNow = true;

void serverCallback(RemoteUIServerCallBackArg arg){
    switch (arg.action) {
        case CLIENT_DID_SET_PRESET:
        case CLIENT_UPDATED_PARAM:
            bRecalcNow = true;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToFile("log.txt", true);
    //ofSetLogLevel(OF_LOG_VERBOSE);

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //ofEnableAlphaBlending();
    
    // setup ofxRemoteUI
    OFX_REMOTEUI_SERVER_SET_CALLBACK(serverCallback);
    OFX_REMOTEUI_SERVER_SETUP(); 	//start server
    TIME_SAMPLE_SET_FRAMERATE(60);
    // TODO: setup params here
    OFX_REMOTEUI_SERVER_LOAD_FROM_XML();
}

//--------------------------------------------------------------
void ofApp::update(){
    TS_START("Update");

    float dt = (1.f/60.f); // elapsed time (60 fps)

    if(bRecalcNow){
        // TODO: perform post-param-change updates
    }
    
    TS_STOP("Update");
}

//--------------------------------------------------------------
void ofApp::draw(){
    TS_START("Draw");

    TS_STOP("Draw");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
	
}
