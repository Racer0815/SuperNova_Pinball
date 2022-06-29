#include <Shiftout.h>


Shiftout Test(6,4,5);

void setup() {
 Test.Pin_HIGH(1,0);
}

void loop() 
{
  Test.Pin_HIGH(3,0);
  delay(500);
  Test.Pin_LOW(3,0);
  delay(500);
}
