#include "mute.h"
#include <Arduino.h>

int value;
int pin;
int sliderId;

Mute::Mute(int id, int p){
    pin = p;
    value = getValue();
    sliderId = id;
}

int Mute::getValue(){
    updateValue();
    return value;
}

void Mute::updateValue(){
    value = digitalRead(pin);
}
