#include "config.h"

#ifdef DECORATOR

// Decorator Pattern
// 재포장 기법.
// RDC의 패이지 기법 
// https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

#include <iostream>
#include <string>

class Car {
private:
protected:
    std::string _str;

public:
    Car() {
        _str = "Unknwon Car";
    }

    virtual std::string getDescription() {
        return _str;
    }

    virtual double getCost() = 0;

    virtual ~Car() {
        std::cout << "~Car()\n";
    }
};

class OptionsDecorator : public Car {
private:
protected:
public:
    virtual std::string getDescription() = 0;
    virtual ~OptionsDecorator() {
        std::cout << "~OptionsDecorator()\n";
    }
};

class CarModel1 : public Car {
public:
    CarModel1() {
        _str = "CarModel1";
    }
    
    virtual double getCost() {
        return 31000.23;
    }

    ~CarModel1() {
        std::cout << "~CarModel1()\n";
    }
};

class Navigation : public OptionsDecorator {
private:
    Car* _b;
protected:
public:
    Navigation(Car* b) {
        _b = b;
    }
    
    std::string getDescription()  override {
        return _b->getDescription() + ", Navigation";
    }

    double getCost() {
        return 300.56 + _b->getCost();
    }

    ~Navigation() {
        std::cout<<"~Navigation()\n";
    }
};

class PremiumSoundSystem : public OptionsDecorator {
private:
    Car* _b;
protected:
public :
    PremiumSoundSystem(Car* b) {
        _b = b;
    }
    
    std::string getDescription() override {
        return _b->getDescription() + ", PremiumSoundSystem";
    }

    double getCost() {
        return 0.30 + _b->getCost();
    }

    ~PremiumSoundSystem() {
        std::cout << "~PremiumSoundSystem()\n";
    }
};

class ManualTransmission : public OptionsDecorator {
    Car* _b;
public:
    ManualTransmission(Car *b) {
        _b = b;
    }
    std::string getDescription() override {
        return _b->getDescription() + ", ManualTransmission";
    }
    double getCost() {
        return 0.30 + _b->getCost();
    }
    ~ManualTransmission() {
        std::cout << "~ManualTransmission()\n";
    }
};

class CarDecoratorExample {
public:
    void execute() {
        Car* b = new CarModel1();

        std::cout << "Base model of " << b->getDescription() << " costs $" << b->getCost() << "\n";
        
        b = new Navigation(b);
        std::cout << b->getDescription() << " will cost you $" << b->getCost() << "\n";
        b = new PremiumSoundSystem(b);
        b = new ManualTransmission(b);
        std::cout << b->getDescription() << " will cost you $" << b->getCost() << "\n";
    
        delete b;
    }
};

int main(int argc, char* argv[])
{
    CarDecoratorExample b;
    b.execute();

    char c;
    std::cin >> c;

    return 0;
}

#endif
