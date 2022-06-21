/*InputProcessor.h - Part of the Supernova_Pinball Library.
Created by Racer0815 June 2022.
https://github.com/Racer0815/SuperNova_Pinball
*/

#ifndef InputProcessor_h
#define InputProcessor_h

#include "Arduino.h"

class InputProcessor
{
public:
  InputProcessor(int Sensor1,int Sensor2,int Sensor3, int Sensor4, int Sensor5, int Sensor6,int threshold);
  void scan_Ports();
  bool get_value(int Sensorport);
  int get_raw_value(int Sensorport);
private:

  int _Sensor1;
  int _Sensor2;
  int _Sensor3;
  int _Sensor4;
  int _Sensor5;
  int _Sensor6;

  bool _SSensor1;
  bool _SSensor2;
  bool _SSensor3;
  bool _SSensor4;
  bool _SSensor5;
  bool _SSensor6;

  int _VSensor1;
  int _VSensor2;
  int _VSensor3;
  int _VSensor4;
  int _VSensor5;
  int _VSensor6;

  int _threshold;
};

#endif
