#include "functions.h"

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


void BPM(int n)
{
	for(inz i = 1; i <= n; i++)
	{
		if(i == 33)
		{	
			dimmen(100, 3);
			dimmen(100, 2);
			drehen(255, 90, 100, 2);
			drehen(100, 75, 100, 3);
		}
		Serial.println(i);
		dimmen(100,1);
		delay(100);dimmen(0,1);
		start = nextBeat(start);
		dimmen(100,4);
		delay(100);
		dimmen(0,4);
		start = nextBeat(start);
	} Serial.println(i);
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



farbeRGB(255,0,0,2);
farbeRGB(0,0,255,3);
dimmen(0, 2);
dimmen(0, 3);
white(1);
white(4);





void loop()
{

}
