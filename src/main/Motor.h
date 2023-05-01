#include <math.h>
#include <Stepper.h>

class Motor
{
  /*
  Motor Class

  All Distances in mm, All Angles in Degrees

  @param id: ID of the Motor, preferably identical to the shield
  @param pinNo: PinNo of the Motor, to be infered from the Datasheet Prototype
  @param wheelRadius: Radius of the Actual Wheel in radius
  @param stepsPerRotation: Steps per Rotation of the Stepper Motor

  */
private:
  int id;
  int wheelRadius;
  Control control;
  int speed;
  int stepsPerRotation;
  int pinA, pinB, pinC, pinD;
  Stepper stepper;
  float convertToRads(float degrees)
  {
    return (degrees / 180) * M_PI;
  }
  float calculateDegrees(float distance)
  {
    float circumference = 2 * M_PI * wheelRadius;
    float degrees = distance / circumference;
    return convertToRads(degrees);
  }

  int calculateSteps(float radians)
  {
    return static_cast<int>((radians / (2 * M_PI)) * 48);
  }

public:
  Motor(
      int id,
      int wheelRadius,
      int stepsPerRotation,
      int pinA,
      int pinB,
      int pinC,
      int pinD,
      Control control)
  {
    this->control = control;
    this->speed = 30;
    this->id = id;
    this->wheelRadius = wheelRadius;
    this->stepsPerRotation = stepsPerRotation;
    this->pinA = pinA;
    this->pinB = pinB;
    this->pinC = pinC;
    this->pinD = pinD;
    Stepper stepper(stepsPerRotation, pinA, pinB, pinC, pinD);
    this->stepper = stepper;
  }
  Motor()
  {
    this->id = 1;
    this->wheelRadius = 75;
  }
  void moveDegrees(float degrees)
  {
    float radians = convertToRads(degrees);
    int steps = calculateSteps(radians);
    moveSteps(steps);
  }
  void moveDistance(float distance)
  {
    float degrees = calculateDegrees(distance);
    moveDegrees(degrees);
  }

  void setSpeed(int speed)
  {
    this->speed = speed;
  }

  void moveSteps(int steps)
  {
    this->stepper.setSpeed(this->speed);
    this->stepper.step(steps);
  }
};
