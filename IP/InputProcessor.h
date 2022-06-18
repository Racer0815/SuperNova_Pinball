#ifndef IP_H
#define IP_H
#include <Arduino.h>

extern int Sensor1;
extern int Sensor2;
extern int Sensor3;
extern int Sensor4;
extern int Sensor5;
extern int Sensor6;

int status_S1;
int status_S2;
int status_S3;
int status_S4;
int status_S5;
int status_S6;

void Scan_input();
void Scan_input(Sensor);
void GetInput(Sensor);

#endif
