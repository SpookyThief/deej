#include "Slider.h"
#include <Arduino.h>

class Slider{
    private:
        int id;
        int value;
        String A_outPin;
        int enablePin;
        int forwardPin;
        int reversPin;
        String direction;
        bool enable;
    
    public: 
        Slider(int id, String a_out, int fw, int bw, int enable){
            Slider::id = id;
            Slider::A_outPin = a_out;
            Slider::forwardPin = fw;
            Slider::reversPin = bw;
            Slider::enablePin = enable;
            
            Slider::direction = "FWD";

            updateValue();
            stop();
            
        }

        void Slider::sliderInit(int id, String a_out, int fw, int bw, int enable){

        }

        void Slider::updateValue(){

        }

        int Slider::getValue(){
            return value;
        }

        void Slider::move(int target){
            
        }

        void Slider::stop(){
            digitalWrite(enablePin, LOW);
            digitalWrite(forwardPin, LOW);
            digitalWrite(reversPin, LOW);
        }
};