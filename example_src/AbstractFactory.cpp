#include "config.h"

#ifdef ABSTRACTFACTORY
#include <iostream>

class IShape {
public :
    virtual void draw() = 0;
};

class Rectangle : public IShape {
public:
    void draw() {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

class Square : public IShape {
public:
    void draw() {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

class Circle : public IShape {
public:
    void draw() {
        std::cout << "Inside Circle::draw() method." << std::endl;
    }
};

class IColor {
public:
    virtual void fill() = 0;
};

class Red : public IColor {
public :
    void fill() {
        std::cout << "Inside Red::fill() method." << std::endl;
    }
};

class Green : public IColor {
public :
    void fill() {
        std::cout << "Inside Green::fill() method." << std::endl;
    }
};

class Blue : public IColor {
public :
    void fill() {
        std::cout << "Inside Blue::fill() method." << std::endl;
    }
};

class IAbstractFactory {
public :
    virtual IColor* getColor(std::string color) = 0;
    virtual IShape* getShape(std::string shape) = 0;
};

class ShapeFactory : public IAbstractFactory{
public:
    IShape* getShape(std::string shapeType) {
        if (shapeType.compare("CIRCLE") == 0 ) {
            return new Circle();
        } else if (shapeType.compare("RECTANGLE") == 0 ) {
            return new Rectangle();
        } else if (shapeType.compare("SQUARE") == 0 ) {
            return new Square();
        } else {
            return 0;
        }
    }

    IColor* getColor(std::string color) {
        return NULL;
    }
};

class ColorFactory : public IAbstractFactory {
public:
    IShape* getShape(std::string shapeType) {
        return NULL;
    }

    IColor* getColor(std::string color) {
        if (color.compare("RED") == 0 ) {
            return new Red();
        } else if (color.compare("GREEN") == 0 ) {
            return new Green();
        } else if (color.compare("BLUE") == 0 ) {
            return new Blue();
        } else {
            return 0;
        }
    }
};

class FactoryProducer {
public:
    static IAbstractFactory* getFactory(std::string choice) {
        if (choice.compare("SHAPE") == 0) {
            return new ShapeFactory();
        } else if (choice.compare("COLOR") == 0) {
            return new ColorFactory();
        }
        return NULL;
    }
};

int main(int argc,char* argv[])
{
    std::cout<< "main()" <<std::endl;

    IAbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");

    IShape* shape1 = shapeFactory->getShape("CIRCLE");
    shape1->draw();

    IShape* shape2 = shapeFactory->getShape("RECTANGLE");
    shape2->draw();

    IShape* shape3 = shapeFactory->getShape("SQUARE");
    shape3->draw();

    IAbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");

    IColor* color1 = colorFactory->getColor("RED");
    color1->fill();

    IColor* color2 = colorFactory->getColor("GREEN");
    color2->fill();

    IColor* color3 = colorFactory->getColor("BLUE");
    color3->fill();

    return 0;
}
#endif
