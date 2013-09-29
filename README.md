Makey-makey-using-arduino-uno-r3-Multiple-inputs-


For making makey makey using  Arduino Leonardo refer to alpesh vitha tutorial given below


http://www.youtube.com/watch?v=WDPTA0-fbNE

You need to add library to your arduino software the following are the links to the library
https://github.com/sebnil/Moving-Avarage-Filter--Arduino-Library-
https://github.com/SFE-Chris/UNO-HIDKeyboard-Library



You need to program arduino uno r3 in dfu mode for making makey makey please refer to the following tutorials
http://www.youtube.com/watch?v=fSXZMVdO5Sg
http://www.youtube.com/watch?v=1unTKKGd8qs
=================================================
//Source for multiple inputs
#include <HIDKeyboard.h>
#include <MovingAvarageFilter.h>

MovingAvarageFilter movingAvarageFilter(20);
MovingAvarageFilter movingAvarageFilter1(20);
MovingAvarageFilter movingAvarageFilter2(20);
MovingAvarageFilter movingAvarageFilter3(20);
HIDKeyboard Keyboard;
boolean check = false;

boolean check1 = false;

boolean check2 = false;

boolean check3 = false;


 

void setup() {
     
Keyboard.begin();
 
}

 
void loop() {        

 

// declare input and output variables

 

float input =  analogRead(0);

float input1 =  analogRead(1); 

float input2 =  analogRead(2);

float input3 =  analogRead(3);

 

float output = 0;

float output1 = 0;

float output2 = 0;

float output3 = 0;

 
output = movingAvarageFilter.process(input);

output1 = movingAvarageFilter1.process(input1);

output2 = movingAvarageFilter2.process(input2);

output3 = movingAvarageFilter3.process(input3);

 
////  key "w"///////////////////////////////////////////////////

if (output < 300 ) {   // you can change this parameter to fine tune the sensitivity

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
 

 ////  key "a"///////////////////////////////////////////////////

if (output1 < 300 ) {   // you can change this parameter to fine tune the sensitivity

if (!check1){         

Keyboard.pressKey('a');
Keyboard.releaseKey();       

       

check1 = !check1;   

  }         

  }

if (output1 >600) {     

  if (check1){               

  check1 = !check1;   

  }     

  }

 

  ////  key "d"///////////////////////////////////////////////////

 

if (output2 < 300 ) {   // you can change this parameter to fine tune the sensitivity

if (!check2){         

Keyboard.pressKey('d');
Keyboard.releaseKey();      

      

check2 = !check2;   

  }         

  }

 

if (output2 >600) {     

  if (check2){               

  check2 = !check2;   

  }     

  }


   ////  key "s"///////////////////////////////////////////////////
 
if (output3 < 300 ) {   // you can change this parameter to fine tune the sensitivity

if (!check3){         

Keyboard.pressKey('s');
Keyboard.releaseKey();        

   

check3 = !check3;   

  }         

  }

if (output3 >600) {     

  if (check3){               

  check3 = !check3;   

  }     

  }


}
