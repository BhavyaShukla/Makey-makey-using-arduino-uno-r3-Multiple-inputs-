/* Author:Bhavya Shukla in reference to uno
Single Key*/ 
#include <HIDKeyboard.h>
#include <MovingAvarageFilter.h>
MovingAvarageFilter movingAvarageFilter(20);
HIDKeyboard Keyboard;
boolean check = false;

void setup() {

Keyboard.begin();

}

void loop() {

// declare input and output variables

float input = analogRead(0); // without a real input, looking at the step respons (input at unity, 1)

float output = 0;

output = movingAvarageFilter.process(input);

if (output < 300 ) { // you can change this parameter to fine tune the sensitivity
if (!check){
Keyboard.pressKey('w');
Keyboard.releaseKey();

check = !check;
}
}

if (output >600) {
if (check){
check = !check;
}
}

}
