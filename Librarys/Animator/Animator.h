/*Animator.h - Part of the Supernova_Pinball Library.
Created by Racer0815 June 2022.
https://github.com/Racer0815/SuperNova_Pinball
*/
#ifndef ANIMATOR_h
#define ANIMATOR_h
#include <Arduino.h>

class Animator
{

public:
Animator(int starttick, int tps);
bool timed(int timecode);
bool timed_once(int timestamp);
int get_tick();
void tick();
void reset_tick();
void set_tick(int tick);
void add_tick(int tick);
void remove_tick(int tick);

private:
int _tps;
int _tick;
int _delay;

};
#endif
