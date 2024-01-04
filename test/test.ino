#include"functions.h"

double nextBeat(double);
void n_blinken(int, double&);

void n_blinken(int n, double& start){
for (int i = 0; i < n; i++){
    Serial.println(i);
    dimmen(100,1);
    delay(100);
    dimmen(0,1);
    start = nextBeat(start);
    dimmen(100,4);
    delay(100);
    dimmen(0,4);
    start = nextBeat(start);
  }


}

double nextBeat(double time){
  while (millis() < time + 517.24){

  }
  return time + 517.24;
}


void setup() {
DmxSimple.maxChannel(44);
Serial.begin(9600);

for(int i = 3; i > 0; i--){
  Serial.println(i);
  delay(1000);
}
  Serial.println("START!");
  delay(517*4);
  double start = millis();



drehen(0,150,100,2);
drehen(0,150,100,3);
farbeRGB(255,0,0,2);
farbeRGB(0,0,255,3);
dimmen(0,2);
dimmen(0,3);
white(1);
white(4);


while(true){
    n_blinken(7, start);
    dimmen(100,1);
    dimmen(100,2);
    dimmen(100,3);
    dimmen(100,4);
    delay(100);
    dimmen(0,1);
    dimmen(0,4);
    delay(200);
    dimmen(0,2);
    dimmen(0,3);
    
    start = nextBeat(start);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
