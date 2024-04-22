const int NUM_SLIDERS = 1;
const int NUM_MUTE = 1;
const int analogInputs[NUM_SLIDERS] = {A0};
const int digialInputs[NUM_MUTE] = {2};
 
int analogSliderValues[NUM_SLIDERS];
bool muteValues[NUM_MUTE];
unsigned long lastPressed[NUM_MUTE];


void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
  for (int i = 0; i < NUM_MUTE; i++){
    pinMode(digialInputs[i], INPUT_PULLUP);
  }

  Serial.begin(9600);
}

void loop() {
  updateSliderValues();
  updateMuteValues();
  sendSliderValues(); // Actually send data (all the time)
  // printSliderValues(); // For debug
  delay(10);
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void updateMuteValues(){
  for (int i = 0; i < NUM_MUTE; i++) {
    if(lastPressed[i] <= millis()+(unsigned long) - 300 && !digitalRead(digialInputs[i])){
      muteValues[i] = !muteValues[i];
      lastPressed[i] = millis();
    }
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  builtString += String("M:");

  for (int i = 0; i < NUM_MUTE; i++){
    builtString += String(muteValues[i]);
    if (i < NUM_MUTE-1){
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}


