/*Motordriver.h - Part of the Supernova_Pinball Library.
Created by Racer0815 June 2022.
https://github.com/Racer0815/SuperNova_Pinball
*/
#ifndef Motordriver_h
#define Motordriver_h


#include "Arduino.h"

class Motordriver
{
public:
Motordriver(int pin, int startvoltage);
void run(int voltage);
void stop();
void start(int voltage);
bool is_running();
int get_power();

private:
int _pin;
int _startvoltage;
int _currvoltage;
};

#endif
