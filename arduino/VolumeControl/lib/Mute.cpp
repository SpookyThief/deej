#include "mute.h"
#include <Arduino.h>

int value;
int pin;
int sliderId;

Mute::Mute(int id, int p){
    sliderId = id;
    pin = p;
    updateValue();
}

int Mute::getValue(){
    return value;
}

void Mute::updateValue(){
    value = digitalRead(pin);
}
