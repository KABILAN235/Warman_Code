#include "master.h"

Control control;
Motor motor;
Rover rover;

void setup()
{
  Serial.begin(9600);
  control = Control(pinMode, digitalWrite, analogWrite, digitalRead, analogRead, delay);
  motor = Motor(1, 50, 48, 8, 9, 10, 11, control);
  rover = Rover(motor, motor, 6, 40);
  Serial.begin(9600);
}

void loop()
{
  rover.turnServo(0);
  delay(500);
  rover.turnServo(180);
  delay(500);
}