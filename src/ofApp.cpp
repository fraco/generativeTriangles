#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
//    mouse.x = ofGetMouseX();
//    mouse.y = ofGetMouseY();

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetFrameRate(60);
    ofHideCursor();
    pdM.mouse;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(ofColor::black);
    
    
    //loop that iterates the first class of pointDots (Vertices)
    for (int i = 0; i<num; i++) {
        pdots[i].move();
        pd1 = pdots[i];
        pd1.neighbours.push_back(pd1);
        
        //iterating the second class of pointDots
        for (int j = i+1; j<num; j++) {
            pd2 = pdots[j];
//            pdM = pdots[j]; //MOUSE
        //comparing location of both classes of pointDots
            float d = pd1.loc.distance(pd2.loc);
//            float dM = pd1.loc.distance(pdM.mouse); //MOUSE

            if (d>0 && d<maxDist){
                pd1.neighbours.push_back(pd2);
            }
            
        //[FAIL Attempt] - conditional that sets the threshold of proximity MOUSE
//            if (dM>0 && dM<maxDist){
//                //adding the pointDot to vector-class neighbours
//                pd1.neighbours.push_back(pdM);
//            }
            
        }
        //drawing triangles
        if (pd1.neighbours.size()>1) {
            addTriangles(pd1.neighbours);
        }
    }
    drawTriangles();
    
    ofSetColor(ofColor::white);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
//    cout<<pdM.mouse<<endl;
 
}

//--------------------------------------------------------------
void ofApp::addTriangles(vector<Vertices> otherNeighbours) {
    int s = otherNeighbours.size();
    if (s > 2) {
        for (int i = 1; i < s-1; i ++) {
            for (int j = i+1; j < s; j ++) {
                triangles.addVertex(otherNeighbours[0].loc);
                triangles.addVertex(otherNeighbours[i].loc);
                triangles.addVertex(otherNeighbours[j].loc);
                
                //FIRST closest I've got
//                triangles.addVertex(otherNeighbours[0].loc);
//                triangles.addVertex(otherNeighbours[i].mouse);
//                triangles.addVertex(otherNeighbours[j].loc);
            }
            
                //SECOND closest I've got
//            for (int f = i+1; f < s; f++){
//                triangles.addVertex(otherNeighbours[f].mouse);
//            }

        }
    }
}

//--------------------------------------------------------------
void ofApp::drawTriangles(){
    ofSetColor(ofColor::tan, 12);
    ofFill();
    triangles.drawFaces();
    ofSetColor(ofColor::tan, 18);
    ofSetLineWidth(.5);
    triangles.drawWireframe();
    triangles.clear();
}

void ofApp::keyPressed(int key){
    
    if(key == 'r' || key == 'R'){
        num++;
    } else if (key == 'f' || key == 'F'){
        num--;
    }
}
    


