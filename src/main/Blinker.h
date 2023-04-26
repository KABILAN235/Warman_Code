#include "Control.h"

class Blinker
{
private:
    Control control;
    int pin;
    int delay;
    int increment=0;
public:
    Blinker(int pin,int delay,Control control){
        this->pin=pin;
        this->control=control;
        this->delay=delay;
        control.pinMode(pin,1);
    };
    Blinker(){
    }
    void blinkLights(){
        control.digitalWrite(pin,1);
        control.delay(delay+increment);
        control.digitalWrite(pin,0);
        control.delay(delay+increment);
        increment++;
    }
};

