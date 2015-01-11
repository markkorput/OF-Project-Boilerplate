#include "ofApp.h"

#include "ofxSuperLog.h"
#include "ofxTimeMeasurements.h"
#include "ofxRemoteUIVars.h"

//--------------------------------------------------------------
// callback function for ofxRemoteUI actions
bool bRecalcNow = true;

void ruiServerCallback(RemoteUIServerCallBackArg arg){
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
    ofEnableAlphaBlending();

    TIME_SAMPLE_SET_FRAMERATE(60);
    // TIME_SAMPLE_ENABLE();

    // setup ofxRemoteUI
    RUI_SETUP();
    RUI_SET_CALLBACK(ruiServerCallback);
    // OFX_REMOTEUI_SERVER_SETUP(); 	//start server
    
    // TODO: setup params here
    RUI_NEW_GROUP("App");
    RUI_DEFINE_VAR_WV(bool, "app-fullscreen", false);

    RUI_LOAD_FROM_XML();
}

//--------------------------------------------------------------
void ofApp::update(){
    TS_START("Update");

    float dt = (1.f/60.f); // elapsed time (60 fps)

    if(bRecalcNow){
        // TODO: perform post-param-change updates
        ofSetFullscreen(RUI_VAR(bool, "app-fullscreen"));
    }
    
    TS_STOP("Update");
}

//--------------------------------------------------------------
void ofApp::draw(){
    TS_START("Draw");

    ofBackgroundGradient(ofColor(150), ofColor(170));

    TS_STOP("Draw");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
            OFX_REMOTEUI_SERVER_SET_VAR(bool, "app-fullscreen", !RUI_VAR(bool, "app-fullscreen"));
            bRecalcNow = true;
            break;
    }
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
