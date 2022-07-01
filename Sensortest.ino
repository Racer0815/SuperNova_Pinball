#include <InputProcessor.h>

int value = 0;
int value2 = 0;

InputProcessor inputs(A0,A1,A2,A3,A4,A5,100);
void setup() {
Serial.begin(9600);
Serial.println("Sensor Test");
Serial.println("running...");

}

void loop() {

inputs.scan_Ports();

value2 = inputs.get_raw_value(2);
value = inputs.get_raw_value(1);
if(value > 100)
{
  Serial.print("Error bei Sensor1, Test beendet mit dem Wert ");
  Serial.println(value);
  Serial.print("Nach ");
  Serial.print(millis());
  Serial.println(" milisekunden");
  delay(9999999999999);
}

if(value2 > 100)
{
  Serial.print("Error bei Sensor2, Test beendet mit dem Wert ");
  Serial.println(value2);
  Serial.print("Nach ");
  Serial.print(millis());
  Serial.println(" milisekunden");
  delay(9999999999999);
}
}
