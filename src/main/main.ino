#include "master.h"

Control control;
Motor leftMotor;
Motor rightMotor;
Rover rover;

String command,value;

void setup()
{
  Serial.begin(9600);
  control = Control(pinMode, digitalWrite, analogWrite, digitalRead, analogRead, delay);
  leftMotor = Motor(1, 50, 48, 47, 49, 51, 53, control);
  rightMotor=Motor(2, 50, 48, 46, 48, 50, 52, control);
  rover = Rover(leftMotor, rightMotor, 9, 40);
  Serial.begin(9600);

}

bool startNow=false;

void loop()
{
  if(Serial.available()){
        command = Serial.readStringUntil('#');
        if(command=="startNow"){
          startNow=true;
          return;
        }
        value=Serial.readStringUntil("\n");
        if(command=="rss"){
          rover.setSpeed(value.toInt());
        }
        else if(command=="rmd"){
          rover.moveDistance(value.toFloat());
        } 
        else if(command=="rtd"){
          rover.turnDegrees(value.toFloat());
        }
        else if(command=="rts"){
          Serial.println("Turn Servo");
          rover.turnServo(value.toFloat());
        }
        else if(command=="lmss"){
          leftMotor.setSpeed(value.toInt());
        }
        else if(command=="lms"){
          leftMotor.moveSteps(value.toInt());
        }
        else if (command="lmd"){
          leftMotor.moveDistance(value.toFloat());
        }
        else if(command=="lmrd"){
          leftMotor.moveDegrees(value.toFloat());
        }
         else if(command=="rmss"){
           Serial.println("Right Motor Set Speed");
          rightMotor.setSpeed(value.toInt());
        }
        else if(command=="rms"){
          Serial.println("Right Motor Step");
          rightMotor.moveSteps(value.toInt());
        }
        else if (command="rmd"){
          Serial.println("Right Motor Move Distance");
          rightMotor.moveDistance(value.toFloat());
        }
        else if(command=="rmrd"){
          Serial.println("Right Motor Rotate Degrees");
          rightMotor.moveDegrees(value.toFloat());
        }    
    }
    // rover.turnServo(0);
    // delay(500);
    // rover.turnServo(90);
    // delay(500);
    rightMotor.setSpeed(125);
    rightMotor.moveSteps(1000);
  }


