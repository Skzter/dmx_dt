#include"C:\Users\bruno\OneDrive\HTWK\Digitaltechnik_I\Arduino\functions.h"

void nextBeat(int);

double nextBeat(double time){
  while (millis() < time + 517.24){

  }
  return time + 517.24;
}
void setup() {

/*synchrones blinken
double start = millis();
farbeRGB(255,0,200,1);
while(true){
  dimmen(100,1);
  delay(100);
  dimmen(0,1);
  start = nextBeat(start);
}*/


}

void loop() {
  // put your main code here, to run repeatedly:

}
