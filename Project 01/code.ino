const int ledPin = 9;   // can be any Pin
const int gasButtonPin = 2;
const int brakeButtonPin = 3;


void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(gasButtonPin, INPUT);
    pinMode(brakeButtonPin, INPUT);

    digitalWrite(gasButtonPin, HIGH);
    digitalWrite(brakeButtonPin, HIGH);
}

int inputDelay = 500;
long lastTime = 0;
int ledState = LOW;

void loop(){
    if(digitalRead(gasButtonPin) == LOW){
        inputDelay--; 
    }else if(digitalRead(brakeButtonPin) == LOW){
        inputDelay++;
    }

    inputDelay = constrain(inputDelay, 10, 5000);
    if((lastTime + inputDelay) < millis()){
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      lastTime = millis();
    }
    delay(10);
}