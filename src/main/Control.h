#include <stdint.h>

class Control
{
private:
    void (*pinModeFunction)(uint8_t, uint8_t);
    void (*digitalWriteFunction)(uint8_t, uint8_t);
    void (*analogWriteFunction)(uint8_t, int);
    int (*digitalReadFunction)(uint8_t);
    int (*analogReadFunction)(uint8_t);
    void (*delayFunction)(long);
    // void (*servoSetSpeed)(long);
    // void (*servoStep)(int);

public:
    Control(
        void (*pinMode)(uint8_t, uint8_t),
        void (*digitalWrite)(uint8_t, uint8_t),
        void (*analogWrite)(uint8_t, int),
        int (*digitalRead)(uint8_t),
        int (*analogRead)(uint8_t),
        void (*delay)(long))
    {
        this->pinModeFunction = pinMode;
        this->digitalWriteFunction = digitalWrite;
        this->analogWriteFunction = analogWrite;
        this->digitalReadFunction = digitalRead;
        this->analogReadFunction = analogRead;
        this->delayFunction = delay;
    }

    void pinMode(uint8_t pin, uint8_t mode)
    {
        this->pinModeFunction(pin, mode);
    }

    void digitalWrite(uint8_t pin, uint8_t value)
    {
        this->digitalWriteFunction(pin, value);
    }

    void analogWrite(uint8_t pin, int value)
    {
        this->analogWriteFunction(pin, value);
    }

    int digitalRead(uint8_t pin)
    {
        return this->digitalReadFunction(pin);
    }
    int analogRead(uint8_t pin)
    {
        return this->analogReadFunction(pin);
    }

    void delay(long time_ms)
    {
        this->delayFunction(time_ms);
    }
    Control() {}
};
