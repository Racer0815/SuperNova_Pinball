#include "Pinball.h"
#include <Arduino.h>



void Pin_high(byte shiftregister,int bit)
{
  if(shiftregister == 1){
    bitSet(register1, bit);
  }
  if(shiftregister == 2){
    bitSet(register2, bit);
  }
  if(shiftregister == 3){
    bitSet(register3,bit);
  }
  ShiftOut();
}


void Pin_low(byte shiftregister,int bit)
{
  if(shiftregister == 1){
    bitClear(register1, bit);
  }
  if(shiftregister == 2){
    bitClear(register2, bit);
  }
  if(shiftregister == 3){
    bitClear(register3,bit);
  }
  ShiftOut();
}

void ShiftOut()
{
  digitalWrite(latch, LOW);
  shiftOut(data, clock, LSBFIRST, register1);
  shiftOut(data, clock, LSBFIRST, register2);
  shiftOut(data, clock, LSBFIRST, register3);
  digitalWrite(latch, HIGH);
}
