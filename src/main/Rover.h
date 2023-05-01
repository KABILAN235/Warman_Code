// #include "Motor.h"
#include <Servo.h>

class Rover
{
private:
    Motor leftMotor;
    Motor rightMotor;
    Servo servo;
    float span;
    float currentServoReading;

public:
    Rover(Motor leftMotor, Motor rightMotor, uint8_t servoPin, float span)
    {
        this->leftMotor = leftMotor;
        this->rightMotor = rightMotor;
        this->span = span;
        Servo servo;
        servo.attach(servoPin);
        this->servo = servo;
        this->currentServoReading = 0;
    }
    Rover() {}

    void moveDistance(float distance)
    {
        int steps = leftMotor.getSteps(distance);
        for (int i = 0; i < abs(steps); i++)
        {
            if (steps > 0)
            {
                leftMotor.moveSteps(1);
                rightMotor.moveSteps(-1);
            }
            else
            {
                leftMotor.moveSteps(1);
                rightMotor.moveSteps(-1);
            }
        }
    }

    void turnDegrees(float degrees)
    {
        float radius = span / 2;
        float circumference = 2 * M_PI * radius;
        float traverseDistance = (degrees / 360) * circumference;
        int steps = leftMotor.getSteps(traverseDistance);
        for (int i = 0; i < abs(steps); i++)
        {
            if (steps > 0)
            {
                leftMotor.moveSteps(1);
                rightMotor.moveSteps(1);
            }
            else
            {
                leftMotor.moveSteps(-1);
                rightMotor.moveSteps(-1);
            }
        }
    }

    void turnServo(float degrees)
    {
        this->currentServoReading = degrees;
        this->servo.write(degrees);
    }

    float getServoDegrees(float degrees)
    {
        return this->currentServoReading;
    }
};
