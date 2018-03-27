//
//  CircleHandler.cpp
//  a08
//
//  Created by ViniGodoy on 27/03/18.
//

#include "CircleHandler.h"
#include "ofApp.h"

CircleHandler::CircleHandler(ofApp* destination) : destination(destination)
{
    
}
void CircleHandler::operator()(const Button& source)
{
    destination->isDrawingCircle = !destination->isDrawingCircle;
}
