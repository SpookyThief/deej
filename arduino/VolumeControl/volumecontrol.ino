#include "lib/Slider.h"
#include "lib/Util.h"
#include "lib/mute.h"
#include <vector>

using namespace std;


const int NUM_SLIDERS = 1;


int analogPins[NUM_SLIDERS];
vector<Slider> sliders;
vector<Mute> mutes;

void setup(){
    pinMode(A0, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    sliders.push_back(Slider(0, A0, 3,4,5));
    mutes.push_back(Mute(0,7));
    

    Serial.begin(9600);
}

void loop(){
    for (int i; i < NUM_SLIDERS; i++){
        sliders.at(i).updateValue();
    }
    Util::sendValues(sliders, mutes);
    delay(10);
}