#include "Slider.h"

const int NUM_SLIDERS = 1;


int analogPins[NUM_SLIDERS];
Slider sliders[NUM_SLIDERS];

void setup(){
    pinMode(A0, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    sliders[0] = Slider(0, A0, 3,4,5); 
}

void loop(){

}