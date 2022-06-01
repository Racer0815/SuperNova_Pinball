#ifndef PINBALL_H
#define PINBALL_H
#include <Arduino.h>
extern byte register1;
extern byte register2;
extern byte register3;

extern int data;
extern int clock;
extern int latch;

void Pin_high(byte shiftregister,int bit);
void Pin_low(byte shiftregister,int bit);
#endif
