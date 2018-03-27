#include "ofApp.h"

#include <functional>

ofApp::ofApp() 
:  ofBaseApp(),
	isDrawingSquare(false), 
	isDrawingCircle(false),
    circleHandler(this)
{
    //Utilizamos as funções make_unique ou make_shared para criar os smart pointers
    btnCircle = std::make_unique<Button>(100, 100, 100, 50);
	btnSquare = std::make_unique<Button>(300, 100, 100, 50);
}
//--------------------------------------------------------------
void ofApp::setup(){
    //Registramos 2 lambdas como observadores dos botões.
    //Alternativa 1. Utilizando um functor
    btnCircle->setObserver(circleHandler);
    
    //Alternativa 2. Utilizando lambda
    btnSquare->setObserver([this](const Button&) {
        isDrawingSquare = !isDrawingSquare;
    });

	btnCircle->setup();
	btnSquare->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    btnCircle->update();
	btnSquare->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	btnCircle->draw();
	btnSquare->draw();

    //C√≥digo para realizar o desenho ap√≥s o bot√£o clicado
	if (isDrawingSquare)
	{
		ofSetColor(0, 0, 255);
		ofDrawRectangle(
			btnSquare->getX(), 
			btnSquare->getY() + btnSquare->getH() + 50, 
			25, 
			25
		);
	}

	if (isDrawingCircle) 
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(
			btnCircle->getX(), 
			btnCircle->getY() + btnCircle->getH() + 50, 
			25
		);
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
