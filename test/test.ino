#include"functions.h"

void nextBeat(int);

double nextBeat(double time){
  while (millis() < time + 517.24){

  }
  return time + 517.24;
}
void setup() {
double start = millis();
farbeRGB(255,0,200,2);


/*synchrones blinken

while(true){
  dimmen(100,1);
  delay(100);
  dimmen(0,1);
  start = nextBeat(start);
}*/

//synchrones Nicken

while(true){
drehen(180,30,100,2);
delay(200);
dimmen(100,2);
drehen(180,0,100,2);
delay(50);
dimmen(0,2);
start = nextBeat(start);
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
