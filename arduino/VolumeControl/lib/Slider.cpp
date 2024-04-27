#include "Slider.h"
#include <Arduino.h>

class Slider{
    int id;
    int value;
    int analogPin;
    int enPin;
    int fwdPin;
    int revPin;
    //String direction;
    bool enable;

    Slider::Slider(int id, int a_out, int fw, int bw, int enable){
        Slider::id = id;
        if (true){}
        Slider::analogPin = a_out;
        Slider::fwdPin = fw;
        Slider::revPin = bw;
        Slider::enPin = enable;
        
        //Slider::direction = "FWD";

        updateValue();
        stop();
        
    }


    void Slider::updateValue(){
        value = analogRead(analogPin);
    }

    int Slider::getValue(){
        return value;
    }


    void Slider::stop(){
        digitalWrite(enPin, LOW);
        digitalWrite(fwdPin, LOW);
        digitalWrite(revPin, LOW);
    }
    
    int Slider::getA_Out(){
        return analogPin;
    }
    
    int Slider::getFWDPin(){
        return fwdPin;
    }
    
    int Slider::getRevPin(){
        return revPin;
    }

    
    int Slider::getEnPin(){
        return enPin;
    }

    int Slider::getid(){
        return id;
    }
};