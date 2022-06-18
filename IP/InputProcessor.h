#ifndef IP_H
#define IP_H
#include <Arduino.h>

extern int Sensor1;
extern int Sensor2;
extern int Sensor3;
extern int Sensor4;
extern int Sensor5;
extern int Sensor6;

extern int status_S1;
extern int status_S2;
extern int status_S3;
extern int status_S4;
extern int status_S5;
extern int status_S6;

void Scan_input();
void Scan_input(Sensor);
void GetInput(Sensor);

#endif
