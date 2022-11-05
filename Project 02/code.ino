const int pushButtonPin = 2;
const int ledPin = 9;
const int potPin = A0;

void setup(){
  pinMode(pushButtonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  digitalWrite(pushButtonPin, HIGH);
}

int delayTime = 500;
long lastTime = 0;
int ledState = LOW;
int sensorValue = 0;

void loop(){
 if(digitalRead(pushButtonPin) == LOW){
    sensorValue = analogRead(potPin);
 }

  if(millis() > lastTime + sensorValue){
    if(ledState == HIGH){
      ledState = LOW;
    }else{
      ledState = HIGH;
    }

    lastTime = millis();
    digitalWrite(ledPin, ledState);
  }
}