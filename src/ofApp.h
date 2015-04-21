#pragma once

#include "ofMain.h"
#include "vertices.h"
//#include "triangles.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        void keyPressed(int key);
    
    
        int fc, maxDist=121;
        float num =74; //ofVec3f numD(num,num,num); //ofPoint numD;
        Vertices pdots[270];
    
        Vertices pd1, pd2, pdM; //class of dots to see if two dots are near

        ofMesh triangles;
        void drawTriangles();
        void addTriangles(vector<Vertices> otherNeighbours);
    
//    ofPoint mouse;
    
};
