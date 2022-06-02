#ifndef SHIFTOUT_H
#define SHIFTOUT_H
#include <Arduino.h>
extern byte register1;
extern byte register2;
extern byte register3;

extern int data;
extern int clockPin;
extern int latch;

void Pin_high(byte shiftregister,int bit);
void Pin_low(byte shiftregister,int bit);
#endif
