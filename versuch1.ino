#include <DmxSimple.h>
#include "/home/vincent/functions.h"

unsigned long zeit;
double verz = 517.14;

void setup()
{
  DmxSimple.usePin(3);
  DmxSimple.maxChannel(44);
  Serial.begin(9600);

  
  
}

void loop()
{
  
}
