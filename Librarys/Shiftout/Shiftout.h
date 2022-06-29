/*shiftout.h - Part of the Supernova_Pinball Library.
Created by Racer0815 June 2022.
https://github.com/Racer0815/SuperNova_Pinball
*/
#ifndef Shiftout_h
#define Shiftout_h


#include "Arduino.h"

class Shiftout
{
public:
Shiftout(int clock, int data, int latch);
void Pin_HIGH(int Register, int Bit);
void Pin_LOW(int Register, int Bit);
void Shift();

private:
int _clock_pin;
int _data_pin;
int _latch_pin;

byte _shift1;
byte _shift2;
byte _shift3;
};

#endif
