#include "Arduino.h"
#include "InputProcessor.h"

InputProcessor::InputProcessor(int Sensor1,int Sensor2,int Sensor3, int Sensor4, int Sensor5, int Sensor6, int threshold)
{
  pinMode(Sensor1,INPUT);
  pinMode(Sensor2,INPUT);
  pinMode(Sensor3,INPUT);
  pinMode(Sensor4,INPUT);
  pinMode(Sensor5,INPUT);
  pinMode(Sensor6,INPUT);

  _Sensor1 = Sensor1;
  _Sensor2 = Sensor2;
  _Sensor3 = Sensor3;
  _Sensor4 = Sensor4;
  _Sensor5 = Sensor5;
  _Sensor6 = Sensor6;

  _threshold = threshold;
}

void InputProcessor::scan_Ports()
{
  _VSensor1 = analogRead(_Sensor1);
  _VSensor2 = analogRead(_Sensor2);
  _VSensor3 = analogRead(_Sensor3);
  _VSensor4 = analogRead(_Sensor4);
  _VSensor5 = analogRead(_Sensor5);
  _VSensor6 = analogRead(_Sensor6);

  if(_VSensor1 < _threshold)
  {
    _SSensor1 = true;
  }
  else
  {
    _SSensor1 = false;
  }
  if(_VSensor2 < _threshold)
  {
    _SSensor2 = true;
  }
  else
  {
    _SSensor2 = false;
  }
  if(_VSensor3 < _threshold)
  {
    _SSensor3 = true;
  }
  else
  {
    _SSensor3 = false;
  }
  if(_VSensor4 < _threshold)
  {
    _SSensor4 = true;
  }
  else
  {
    _SSensor4 = false;
  }
  if(_VSensor5 < _threshold)
  {
    _SSensor5 = true;
  }
  else
  {
    _SSensor5 = false;
  }
  if(_VSensor6 < _threshold)
  {
    _SSensor6 = true;
  }
  else
  {
    _SSensor6 = false;
  }
}

bool InputProcessor::get_value(int Sensorport)
{
  if(Sensorport == 1)
  {
    return _SSensor1;
  }
  if(Sensorport == 2)
  {
    return _SSensor2;
  }
  if(Sensorport == 3)
  {
    return _SSensor3;
  }
  if(Sensorport == 4)
  {
    return _SSensor4;
  }
  if(Sensorport == 5)
  {
    return _SSensor5;
  }
  if(Sensorport == 6)
  {
    return _SSensor6;
  }
}

int InputProcessor::get_raw_value(int Sensorport)
{
  if(Sensorport == 1)
  {
    return _VSensor1;
  }
  if(Sensorport == 2)
  {
    return _VSensor2;
  }
  if(Sensorport == 3)
  {
    return _VSensor3;
  }
  if(Sensorport == 4)
  {
    return _VSensor4;
  }
  if(Sensorport == 5)
  {
    return _VSensor5;
  }
  if(Sensorport == 6)
  {
    return _VSensor6;
  }
}
