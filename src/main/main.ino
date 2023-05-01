#include "master.h"
Control control;
Motor motor;

void setup()
{
   Serial.begin(9600);
    control=Control(pinMode,digitalWrite,analogWrite,digitalRead,analogRead,delay);
    motor=Motor(1,50,48,8,9,10,11,control);
    Serial.begin(9600);
}

void loop()
{
  motor.setSpeed(40);
  motor.moveSteps(1000);
  delay(3000);

}