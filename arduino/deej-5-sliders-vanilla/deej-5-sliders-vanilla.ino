const int NUM_SLIDERS = 1;
const int NUM_MUTE = 1;
const int analogInputs[NUM_SLIDERS] = {A0};
const int digialInputs[NUM_MUTE] = {2};
const int forwardPins[NUM_SLIDERS] = {4};
const int reversPins[NUM_SLIDERS] = {5};
const int enable = 3;

int analogSliderValues[NUM_SLIDERS];
bool muteValues[NUM_MUTE];
unsigned long lastPressed[NUM_MUTE];


void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
    
    pinMode(enable, OUTPUT);
    digitalWrite(enable, LOW);
    
    pinMode(forwardPins[i], OUTPUT);
    pinMode(reversPins[i], OUTPUT);
    digitalWrite(forwardPins[i], LOW);
    digitalWrite(reversPins[i], LOW);
  }
  for (int i = 0; i < NUM_MUTE; i++){
    pinMode(digialInputs[i], INPUT_PULLUP);
  }

  Serial.begin(9600);
}

void loop() {
  updateSliderValues();
  updateMuteValues();
  sendValues(); // Actually send data (all the time)
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

void sendValues() {
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

void moveSliders(int targetPos[], int toMove[]){
  int num_toMove = arrlength(toMove);
  int currentPos[num_toMove];

  for(int i = 0; i < num_toMove; i++){
    currentPos[i] = analogRead(analogInputs[toMove[i]]);

  }
}



int arrlength(int arr[]){
  if(sizeof(arr)< sizeof(int)){
    return 0;
  }
  return sizeof(arr)/sizeof(int);
}

void setDirection(int direction, int sliderID){
  if(direction == 2){
    digitalWrite(reversPins[sliderID], LOW);
    digitalWrite(forwardPins[sliderID], HIGH);
  }else if (direction == 1){
    digitalWrite(reversPins[sliderID], HIGH);
    digitalWrite(forwardPins[sliderID], LOW);
  }else{
    digitalWrite(reversPins[sliderID], LOW);
    digitalWrite(forwardPins[sliderID], LOW);
  }
}