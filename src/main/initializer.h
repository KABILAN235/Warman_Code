#include<iostream>

class Initializer
{
private:
    void (*pinMode)(uint8_t, uint8_t );
public:
    Initializer(void (*pinMode)(uint8_t, uint8_t )){
        this->pinMode=pinMode;
    };
    Initializer(){
        assert("No Pinmode Supplied");
    }
    

    void getEverythingSetup(){
        
    }
};

