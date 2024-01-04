#include <DmxSimple.h>
#include "functions.h"

void setup()
{
  DmxSimple.usePin(3);
  DmxSimple.maxChannel(44);
  Serial.begin(9600);

  farbeRGB(255,0,0,1);
  farbeRGB(255,0,0,4);
  farbeRGB(0,0,255,2);
  farbeRGB(0,0,255,3); 

  drehen(180, 5, 100, 2);
  drehen(180, 5, 100,3);

  
  
}

void loop()
{
  
}
