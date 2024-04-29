#include "Util.h"
#include "Slider.h"
#include "mute.h"
#include <iostream>
#include <vector>

using namespace std;

int Util::arrlength(int arr[]){
  if(sizeof(arr)< sizeof(int)){
    return 0;
  }
  return sizeof(arr)/sizeof(int);
}

int Util::arrlength(Slider arr[]){
  if(sizeof(arr)< sizeof(Slider)){
    return 0;
  }
  return sizeof(arr)/sizeof(Slider);
}

void Util::sendValues(vector<Slider> sliders, vector<Mute> mutes) {
  String builtString = String("");
  int numSliders = sliders.size();
  int numMutes = mutes.size();


  for (int i; i < numSliders; i++) {
    builtString += String((int)sliders.at(0).getValue());

    if (i < numSliders - 1) {
      builtString += String("|");
    }
  }
  builtString += String("M:");

  for (int i = 0; i < numMutes; i++){
    builtString += String(mutes.at(i).getValue());
    if (i < numMutes - 1){
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

Slider Util::getSliderbyID(int id, vector<Slider> sliders){
  for (Slider slider : sliders){
     if(slider.getid() == id){
      return slider;
     }
     continue;
  }
  return;
}
