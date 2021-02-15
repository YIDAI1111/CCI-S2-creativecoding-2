#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    
    //Initialize the drawing variables
    for (int i = 0; i < ofGetWidth(); ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
    // Maximilian audio stuff
    int sampleRate = 44100; /* Sampling Rate */
    int bufferSize= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    myClock.setTempo(120);
    myClock.setTicksPerBeat(4);
    
    mySample.load(ofToDataPath("endMusic.wav"));
    // Setup ofSound
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    gui.setup();
    
    gui.add(intSlider.setup("int slider", 64, 3, 64));
    gui.add(floatSlider.setup("float slider", 30.0, 0.0, 300.0));
    
    gui.add(toggle.setup("toggle", false));
    gui.add(button.setup("button"));
    gui.add(label.setup("label","THIS IS A LABEL"));
    
    gui.add(intField.setup("int field", 100, 0, 100));
    gui.add(floatField.setup("float field", 100.0, 0.0, 100.0));
    gui.add(textField.setup("text field", "text"));
    
    gui.add(vec2Slider.setup("vec2 slider", ofVec2f(0,0), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(vec3Slider.setup("vec3 slider", ofVec3f(100, 150, 90), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));
    gui.add(vec4Slider.setup("vec4 slider", ofVec4f(0, 0, 0, 0), ofVec4f(0, 0, 0, 0), ofVec4f(255, 255, 255, 255)));
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /////////////// waveform
//    ofTranslate(0, ofGetHeight()/2);
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    ofSetColor(255+100*myOsc1.sinewave(myFreq/10), intSlider, 150+100*myOsc1.coswave(myFreq/10));
    ofFill();
    ofDrawLine(0, 0, 1, waveform[1] * ofGetHeight()/2.); //first line
    for(int i = 1; i < (ofGetWidth() - 1); i=i+5) {
        ofDrawLine(i+vec2Slider->x, waveform[i]+vec2Slider->y , i + 1, waveform[i+1] * ofGetHeight()/2.);
        
//        ofDrawCircle(0, 0, 1, waveform[1] * ofGetHeight()/2.); //first line
//        for(int i = 1; i < (ofGetWidth() - 1); ++i) {
//            ofDrawCircle(i+ vec3Slider->x, waveform[i] * ofGetHeight()/2.+vec3Slider->y, waveform[i+1] * ofGetHeight()/2.);
            
//            ofDrawCircle(i, waveform[i] * ofGetHeight()/2., i + vec2Slider->x, waveform[i+1] * ofGetHeight()/2.+vec2Slider->y);
            
    }
    
//    if (button) {
//        ofSetColor(ofRandom(vec3Slider->x), ofRandom(vec3Slider->y), ofRandom(vec3Slider->z));
//    }
//  ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 128);
//
//    ofSetCircleResolution(intSlider);
    ofSetColor(vec4Slider->x, vec4Slider->y, vec4Slider->z, vec4Slider->w);
//    ofDrawCircle(vec2Slider->x, vec2Slider->y, 128);
//
    gui.draw();
   
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t nChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++)
    {
        // handle input here
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    
    int time;
    time = ofGetElapsedTimef();
    std::size_t outChannels = output.getNumChannels();
    for (int i = 0; i < output.getNumFrames(); ++i){
        
//        myClock.ticker();
//        if (myClock.tick && ofRandom(1.0)>0.5) {
//            myFreq += 100;
//
//        }
//
//        if (myClock.tick && ofRandom(1.0) < 0.25) {
//            myFreq -= 200;
//        }
        
        if (myClock.tick && time % 2 == 1) {
            myFreq +=3*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        }else {
            myFreq -=3*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        }
//      output[i * outChannels] = myOsc1.square(532) * 0.5;
//      output[i * outChannels] = myOsc1.sinewave(220 + (myOsc2.sinewave(0.1)*100)) * 0.5;
//      output[i * outChannels] = myOsc1.sinewave(220 + (myOsc2.sinewave(400)*100)) * 0.5;
//      output[i * outChannels] = myOsc1.sinewave(myFreq + abs(myOsc2.sinewave(0.4) * myOsc3.coswave(myFreq))) * (ofRandom(0.01) + 0.35);
//        output[i * outChannels] = myOsc1.sinewave(myFreq + abs(myOsc2.sinewave(43.066) * myOsc3.coswave(myFreq)*0.043))*0.6*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        
        output[i * outChannels] = myOsc1.sinewave(myFreq + abs(myOsc2.sinewave(43.066) * myOsc3.coswave(myFreq)*0.043))*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        
        
        output[i * outChannels + 1] = output[i * outChannels];
        
        
        float myOut = mySample.play(-1.5);
        //Hold the values so the draw method can draw them
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        } else {
            waveIndex = 0;
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
