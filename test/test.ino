#include"functions.h"

void nextHalfBeat(double&);
void n_blinken(int, double&);

void n_blinken(int n, double& start){
for (int i = 0; i < n; i++){
    Serial.println(i);
    dimmen(100,1);
    delay(100);
    dimmen(0,1);
    nextHalfBeat(start);
    dimmen(100,4);
    delay(100);
    dimmen(0,4);
    nextHalfBeat(start);
  }


}

void nextHalfBeat(double& time){
  while (millis() < time + 517.24/2){

  }
  time += 517.24/2;
}


void setup() {
DmxSimple.maxChannel(44);

//countdown
Serial.begin(9600);

for(int i = 5; i > 0; i--){
  Serial.println(i);
  delay(1000);
}
  Serial.println("START!");

double start = millis();

drehen(0,150,100,2);
drehen(0,150,100,3);
farbeRGBW(0,0,0,255,1);
farbeRGBW(255,255,0,0,2);
farbeRGBW(0,0,0,255,4);
dimmen(0,2);
dimmen(0,3);
dimmen(0,1);
dimmen(0,4);

//start bei 08:79 sekunden

for (int i = 1; i <= 60; i++){
 
  //synchronisation auf beat
  switch(i){
  case 10: case 12: case 14: case 16:
    dimmen(100,2);
    break;
  case 11: case 13: case 15:
    dimmen(0,2);
    break;
  case 17: //schuss
    dimmen(0,2);
    farbeRGBW(0,0,0,255,2);
    farbeRGBW(0,0,0,255,3);
    farbeRGBW(0,0,0,255,1);
    farbeRGBW(0,0,0,255,4);
    break;
  case 18: 
    drehen(540,0,25,2);
    drehen(540,0,25,3);
    break;
  case 30: 
    drehen(0,0,25,2);
    drehen(0,0,25,3);
    break;
  case 48:
    dimmen(0,1);
    dimmen(0,4);
    farbeRGBW(255,0,255,0,2);
    farbeRGBW(255,0,255,0,2);
    dimmen(20,2);
    dimmen(20,3);
    drehen(0,180,10,2);
    drehen(0,180,10,3);
    break;
  case 55:
    drehen(0,150,100,2);
    drehen(0,150,100,3);
  case 56:

    farbeRGBW(255,0,0,0,2);
    farbeRGBW(255,0,0,0,3);
    farbeRGBW(255,0,0,0,1);
    farbeRGBW(255,0,0,0,4);
    break;


  }

  //nach Schuss
  if (i >= 18 and i < 48){
     if(i%2){
      farbeRGBW(255,0,0,0,1);
      farbeRGBW(255,0,0,0,2);
      dimmen(0,4);
      dimmen(0,3);
    }else{
      farbeRGBW(0,0,255,0,3);
      farbeRGBW(0,0,255,0,4);
      dimmen(0,1);
      dimmen(0,2);
    }  
  }
    nextHalfBeat(start);
//synchronisation um halben beat verschoben (snare am anfang)

  if (i < 17 or ( i > 52 and i < 56)){  //vor schuss
    if(i%2){
      farbeRGBW(0,0,0,255,1);
      delay(100);
      dimmen(0,1);
    }else{
      farbeRGBW(0,0,0,255,4);
      delay(100);
      dimmen(0,4);
   }
  }
  
 
    nextHalfBeat(start);
}
}

void loop() {/*
drehen(180,0,100,2);
delay(1000);
drehen(100,0,100,2);
delay(1000);
*/

  // put your main code here, to run repeatedly:

}
