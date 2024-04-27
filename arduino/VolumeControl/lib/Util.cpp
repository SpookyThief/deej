#include "Util.h"
#include "Slider.h"
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

void Util::sendValues(Slider sliders[], int muteVal[]) {
  String builtString = String("");
  int numSliders = Util::arrlength(sliders);
  int numMutes = Util::arrlength(muteVal);


  for (int i = 0; i < numSliders; i++) {
    builtString += String((int)sliders[i].getValue());

    if (i < numSliders - 1) {
      builtString += String("|");
    }
  }
  builtString += String("M:");

  for (int i = 0; i < numMutes; i++){
    builtString += String(muteVal[i]);
    if (i < numMutes - 1){
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

Slider getSliderbyID(int id, vector<Slider> sliders){
  for (Slider slider : sliders){
     if(slider.getid() == id){
      return slider;
     }
     return;
  }
}
