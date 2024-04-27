#include "lib/Slider.h"
#include "lib/Util.h"
#include <vector>

using namespace std;


const int NUM_SLIDERS = 1;


int analogPins[NUM_SLIDERS];
vector<Slider> sliders;
int mutes[];

void setup(){
    pinMode(A0, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    sliders[0] = Slider(0, A0, 3,4,5);
    

    Serial.begin(9600);
}

void loop(){
    for (int i; i < NUM_SLIDERS; i++){
        sliders[i].updateValue();
    }
    Util::sendValues(sliders, mutes);
    delay(10);
}