/*Motordriver.cpp - Part of the Supernova_Pinball Library.
Created by Racer0815 June 2022.
https://github.com/Racer0815/SuperNova_Pinball
*/
#include "Arduino.h"
#include "Motordriver.h"


Motordriver::Motordriver(int pin, int startvoltage)
{
    pinMode(pin,OUTPUT);
    digitalWrite(pin,LOW);

    _pin = pin;
    _startvoltage = startvoltage;
    _currvoltage = 0;
}

void Motordriver::start(int voltage)
{
    if(_currvoltage == 0 && voltage > 0)
    {
    digitalWrite(_pin,_startvoltage);
    delay(2);
    analogWrite(_pin, voltage);
    _currvoltage = voltage;
    }

};

void Motordriver::stop()
{
    digitalWrite(_pin, LOW);
    _currvoltage = 0;
};

void Motordriver::run(int voltage)
{
   if(_currvoltage != 0 && voltage > 0)
   {
       digitalWrite(_pin, voltage);
       _currvoltage = voltage;
   }
};

bool Motordriver::is_running()
{
    if(_currvoltage == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
};

int Motordriver::get_power()
{
    return _currvoltage;
}
