#include "Arduino.h"
#include "Shiftout.h"


Shiftout::Shiftout(int clock, int data, int latch)
{
    pinMode(clock,OUTPUT);
    pinMode(data,OUTPUT);
    pinMode(latch,OUTPUT);

    _clock_pin = clock;
    _data_pin = data;
    _latch_pin = latch;
}

void Shiftout::Pin_HIGH(int Register,int Bit)
{

    if(Register == 1)
    {
    bitSet(_shift1, Bit);
    }

    if(Register == 2)
    {
    bitSet(_shift2, Bit);
    }

    if(Register == 3)
    {
    bitSet(_shift3,Bit);
    }
    Shift();

}

void Shiftout::Pin_LOW(int Register,int Bit)
{

    if(Register == 1)
    {
    bitClear(_shift1, Bit);
    }

    if(Register == 2)
    {
    bitClear(_shift2, Bit);
    }

    if(Register == 3)
    {
    bitClear(_shift3,Bit);
    }
    Shift();

}

void Shiftout::Shift()
{
    digitalWrite(_latch_pin, LOW);
    shiftOut(_data_pin, _clock_pin, LSBFIRST, _shift1);
    shiftOut(_data_pin, _clock_pin, LSBFIRST, _shift2);
    shiftOut(_data_pin, _clock_pin, LSBFIRST, _shift3);
    digitalWrite(_latch_pin, HIGH);
}
