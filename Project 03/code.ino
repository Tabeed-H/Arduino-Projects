const int rgb_r = 9;
const int rgb_g = 10;
const int rgb_b = 11;

const int pot1_r = A0;
const int pot2_g = A1;
const int pot3_b = A2;

const int fromBtn = 2;
const int toBtn = 3;

void setup(){
  pinMode(rgb_r, OUTPUT);
  pinMode(rgb_g, OUTPUT);
  pinMode(rgb_b, OUTPUT);

  pinMode(fromBtn, INPUT);
  pinMode(toBtn, INPUT);

  digitalWrite(fromBtn, HIGH);
  digitalWrite(toBtn, HIGH);
}

int fromRed = 0;
int fromGreen = 0;
int fromBlue = 0;
int toRed = 255;
int toGreen  = 255;
int toBlue = 255;

int currentStep = 0;
int incrementer = 1;

void loop(){
  int pot1;
  int pot2;
  int pot3;

  pot1 = analogRead(pot1_r);
  pot2 = analogRead(pot2_g);
  pot3 = analogRead(pot3_b);

  if(digitalRead(fromBtn) == LOW){
    fromRed = map(pot1, 0, 1023, 0, 255);
    analogWrite(rgb_r, fromRed);
    fromGreen = map(pot2, 0, 1023, 0, 255);
    analogWrite(rgb_g, fromGreen);
    fromBlue = map(pot3, 0, 1023, 0, 255);
    analogWrite(rgb_b, fromBlue);
  }else if(digitalRead(toBtn) == LOW){
    toRed = map(pot1, 0, 1023, 0, 255);
    analogWrite(rgb_r, toRed);
    toGreen = map(pot2, 0, 1023, 0, 255);
    analogWrite(rgb_g, toGreen);
    toBlue = map(pot3, 0, 1023, 0, 255);
    analogWrite(rgb_b, toBlue);
  }else{
    currentStep = currentStep + incrementer;
    if(currentStep > 255){
      incrementer = -1;
      currentStep = 255;
    }
    if(currentStep < 0){
      incrementer = 1;
      currentStep = 0;
    }

    int ledValue;
    
    ledValue = map(currentStep, 0, 255, fromRed, toRed);
    analogWrite(rgb_r, ledValue);

    ledValue = map(currentStep, 0, 255, fromGreen , toGreen);
    analogWrite(rgb_g, ledValue);

    ledValue = map(currentStep, 0, 255, fromBlue, toBlue);
    analogWrite(rgb_b, ledValue);
    delay(20);
  }
}