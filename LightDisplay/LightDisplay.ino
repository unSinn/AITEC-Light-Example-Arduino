#include "TM1637.h"

#define CLK 2 // Port D2 on Grove Shield
#define DIO 3

#define LIGHT_PIN A0

TM1637 tm1637 = TM1637(CLK,DIO);

void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop()
{
  delay(150);
  while(1)
  {
    int sensorValue = analogRead(LIGHT_PIN);
    tm1637.display(0, (int)(sensorValue / 1000));
    tm1637.display(1, (int)(sensorValue / 100)%10); 
    tm1637.display(2, (int)(sensorValue / 10)%10);
    tm1637.display(3, sensorValue % 10);
    delay(200);
  }
}
