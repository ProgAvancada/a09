//
//  CircleHandler.hpp
//  a08
//
//  Created by ViniGodoy on 27/03/18.
//

#ifndef CircleHandler_h
#define CircleHandler_h

class ofApp;
#include "button.h"

//Functor para lidar com o círculo. Para implementa-lo:
//1. Precisamos saber qual é o ofApp que irá desenhar o circulo. Isso sera inicializado no construtor e guardado
//num atributo da classe.

//2. Precisamos sobrecarregar o operador de () para aceitar uma chamada aceitando como parâmetro um const Button&
class CircleHandler {
    private:
        ofApp* destination;
    public:
        CircleHandler(ofApp* destination);
        void operator()(const Button& source);
};

#endif /* CircleHandler_hpp */
