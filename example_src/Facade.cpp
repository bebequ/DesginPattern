#include "config.h"

#ifdef FACADE

// Facade Pattern
// 여러 동작을 하나의 동작인 Higher-level interface를 만듦.
//
//

#include <iostream>
#include <string>

class Alarm {
public :
    void alarmOn() {
        std::cout << "Alarm is on and house is secured" <<std::endl;
    }
    void alarmOff() {
        std::cout << "Alarm is off and you can go into the house" << std::endl;
    }
};

class Ac {
public :
    void acOn() {
        std::cout << "AC is on "<< std::endl;
    }

    void acOff() {
        std::cout << "AC is off" << std::endl;
    }
};

class Tv {
public :
    void tvOn() {
        std::cout << "TV is on" << std::endl;
    }
    
    void tvOff() {
        std::cout << "TV is off " << std::endl; 
    }
};

class HouseFacade {
    Alarm alarm;
    Ac ac;
    Tv tv;

public:
    HouseFacade() {}
    void goToWork() {
        ac.acOff();
        tv.tvOff();
        alarm.alarmOn();
    }

    void comeHome() {
        alarm.alarmOff();
        ac.acOn();
        tv.tvOn();
    }
};

int main(int argc, char* argv[]) {

    HouseFacade hf;

    hf.goToWork();
    hf.comeHome();

    char c;
    std::cin >> c;
    
    return 0;
}

#endif
