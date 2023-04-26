#include <math.h>
// #include "Control.h"



class Motor
{
    /*
    Motor Class

    All Distances in mm, All Angles in Degrees

    @param id: ID of the Motor, preferably identical to the shield
    @param pinNo: PinNo of the Motor, to be infered from the Datasheet Prototype
    @param wheelRadius: Radius of the Actual Wheel in radius

    */
private:
    int id;
    int pinNo;
    int wheelRadius;
    Control control;
    int speed;
    int stepsPerRotation;
    float convertToRads(float degrees){
        return (degrees/180)*M_PI;
    }
    float calculateDegrees(float distance)
    {
        float circumference = 2 * M_PI * wheelRadius;
        float degrees = distance / circumference;
        return convertToRads(degrees);
    }
    
    int calculateSteps(int degrees){
        return (int)(degrees/M_PI)*stepsPerRotation;
    }

public:
    Motor(int id, int pinNo, int wheelRadius,int stepsPerRotation,Control control)
    {
        this->control=control;
        control.pinMode(pinNo, 1);
        this->id = id;
        this->pinNo = pinNo;
        this->wheelRadius = wheelRadius;
        this->stepsPerRotation=stepsPerRotation;
    }
    Motor()
    {
        this->id = 1;
        this->pinNo = 13;
        this->wheelRadius = 75;
    }
    void moveDegrees(float degrees){
        float radians=convertToRads(degrees);
        int steps=calculateSteps(radians)
        moveSteps(steps);

    }
    void moveDistance(float distance)
    {
        float degrees = calculateDegrees(distance);
        moveDegrees(degrees);
    }

    void moveSteps(int steps){
        control.motorSetSpeed(30);
        control.motorMoveSteps(steps);
    }

    
};
