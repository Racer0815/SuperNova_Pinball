#include "Arduino.h"
#include "Animator.h"

Animator::Animator(int starttick, int tps)
{
  _tps = tps;
  _tick = starttick;
  _delay = 1000 / _tps;
}

void Animator::tick()
{
  delay(_delay);
  _tick = _tick + 1;
}

void Animator::reset_tick()
{
  _tick = 0;
}

void Animator::set_tick(int tick)
{
  _tick = tick;
}

void Animator::add_tick(int tick)
{
  _tick = _tick + tick;
}

void Animator::remove_tick(int tick)
{
  _tick = _tick - tick;
}

int Animator::get_tick()
{
  return _tick;
}

bool Animator::timed_once(int timestamp)
{
  if(_tick == timestamp)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Animator::timed(int timecode)
{
  if(_tick % timecode == 0)
  {
    return true;
  }
  else
  {
    return false;
  }


}
