#include "master.h"
#include <Stepper.h>
Control control;
Motor motor;


void setup()
{
     Stepper myStepper(48, 8,9,10,11);
void stepServo(long step){
    myStepper.step(step);
}
void speedServo(int speed){
   myStepper.setSpeed(step);
}
   control=Control(pinMode,digitalWrite,analogWrite,digitalRead,analogRead,delay,speedServo,stepServo);
   motor=Motor(1,3,50,control);
}

void loop()
{
  motor.moveSteps(30);
  delay(1000);

}