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

int maxHelligkeit = 100; //für fading nach 60 takten

//start bei 08:79 sekunden

for (int i = 1; i <= 70; i++){
 
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
    drehen(540,0,50,2);
    drehen(540,0,50,3);
    break;
  case 28: 
    drehen(540,90,50,2);
    drehen(540,90,50,3);
    break;
  case 32:
    dimmen(0,1);
    dimmen(0,2);
    dimmen(0,3);
    dimmen(0,4);
    farbeRGBW(0,255,0,0,2);
    delay(517.24 / 4);
    dimmen(0,2);
    farbeRGBW(0,255,0,0,1);
    break;
  case 33:
    farbeRGBW(0,0,0,255,1);
    farbeRGBW(0,0,0,255,2);
    farbeRGBW(0,0,0,255,3);
    farbeRGBW(0,0,0,255,4);
    break;
  case 34:
    dimmen(0,1);
    dimmen(0,2);
    dimmen(0,3);
    dimmen(0,4);
    farbeRGBW(0,255,0,0,3);
    delay(517.24 / 4);
    dimmen(0,3);
    farbeRGBW(0,255,0,0,4);
    break;
  case 35:
    farbeRGBW(0,0,0,255,1);
    farbeRGBW(0,0,0,255,2);
    farbeRGBW(0,0,0,255,3);
    farbeRGBW(0,0,0,255,4);
    break;
  
  case 48:  //während Stille nach oben drehen und pink
    dimmen(0,1);
    dimmen(0,4);
    farbeRGBW(255,0,255,0,2);
    farbeRGBW(255,0,255,0,3);
    dimmen(20,2);
    dimmen(20,3);
    drehen(0,180,10,2);
    drehen(0,180,10,3);
    break;
  case 55:
    drehen(0,150,100,2);
    drehen(0,150,100,3);
    break;
  }

  //nach Schuss
  if (i >= 18 and i < 31){
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

  if (i > 35 and i < 48){  //nach übergang
     if(i%2){
      farbeRGBW(0,255,0,0,1);
      farbeRGBW(0,255,0,0,2);
      dimmen(0,4);
      dimmen(0,3);
    }else{
      farbeRGBW(0,0,255,0,3);
      farbeRGBW(0,0,255,0,4);
      dimmen(0,1);
      dimmen(0,2);
    }  
  }

  if (i > 56){
    if (i > 60){
      maxHelligkeit = (70 - i) * 10;
    }

    if (i%2){
      farbeRGBW(255,0,0,0,2);
      farbeRGBW(255,0,0,0,3);
      farbeRGBW(255,0,0,0,1);
      farbeRGBW(255,0,0,0,4);
    }else{
      farbeRGBW(0,0,255,0,2);
      farbeRGBW(0,0,255,0,3);
      farbeRGBW(0,0,255,0,1);
      farbeRGBW(0,0,255,0,4);
    }
  dimmen(maxHelligkeit,1);
  dimmen(maxHelligkeit,2);
  dimmen(maxHelligkeit,3);
  dimmen(maxHelligkeit,4); 
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

  if (i == 32){
    farbeRGBW(0,255,0,0,4);
    dimmen(0,1);
    delay(510.24 / 4);
    farbeRGBW(0,255,0,0,3);
    dimmen(0,4);
  }

  if (i == 34){
    farbeRGBW(0,255,0,0,1);
    dimmen(0,4);
    delay(510.24 / 4);
    farbeRGBW(0,255,0,0,2);
    dimmen(0,1);
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
