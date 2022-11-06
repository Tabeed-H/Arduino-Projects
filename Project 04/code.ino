// This is a common cathode 7-Segment Display 
// OUTPUT
// numbers from 0 - 9;

// SEGMENT POSITIONS USED
/*
            1
    ===================
  =                   =
  =                   =
  =                   =
6 =                   = 2
  =                   =
  =                   =
  =         7         =
    =================
  =                   =
  =                   =
  =                   =
5 =                   = 3
  =                   =
  =                   =
  =        4          =
    =================
*/
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define totalPins 7 // total number of pins selected
#define digits 10 // total number of elements to be displayed

const int displayPins[totalPins] = {A, B, C, D, E, F, G}; // selects pin

// condition of each segment for each digit
// 1 for segment ON
// 0 for segment OFF
const int numbers[digits][7] ={
  {1,1,1,1,1,1,0},//0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,0,0,1},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {1,0,1,1,1,1,1},//6
  {1,1,1,0,0,1,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,0,0,1,1},//9
};


// selects PINS
void setup(){
  for(int i= 0 ;i < totalPins; i++) {
    pinMode(displayPins[i], OUTPUT);
  }
}


// loop counter
int currentDigit = 0;
void loop(){
  // overflow controller
  if(currentDigit >= digits){
    currentDigit = 0;
  }


  // Prints each digit in the numbers array
  // each digit is a array of 1's and 0's represented each state
  print(numbers[currentDigit]);
  currentDigit++;

  //paused the porgram for 5s
  delay(5000);
}


// function that prints each digit
// recieves an array containing states of segments
void print(int* segments){

  // turns of all leds
  // clears display
  for(int i = 0; i < totalPins; i++){
    digitalWrite(displayPins[i], LOW);
  }


  // maps each segment to the state
  for(int i = 0; i < totalPins; i++){
    digitalWrite(displayPins[i], *(segments + i));
  }
}