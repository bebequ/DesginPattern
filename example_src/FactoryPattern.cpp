#include "config.h"

#ifdef FACTORY
#include <iostream>

class IShape {
public:
    virtual void draw() = 0;
};

class Rectangle : public IShape {
public:
    void draw(){
        std::cout<< "Inside Rectagle::draw() method." <<std::endl;
    }
};

class Square : public IShape {
public:
    void draw(){
        std::cout<< "Inside Square::draw() method." <<std::endl;
    }
};

class Circle : public IShape {
public:
    void draw(){
        std::cout<< "Inside Circle::draw() method." <<std::endl;
    }
};

class ShapeFactory {
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
};

int main(int argc,char* argv[])
{
    std::cout<< "main()" <<std::endl;
    ShapeFactory* shapeFactory = new ShapeFactory();
    IShape* shape1 = shapeFactory->getShape("CIRCLE");
    shape1->draw();

    IShape* shape2 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();

    IShape* shape3 = shapeFactory->getShape("SQUARE");
    shape1->draw();

    return 0;
}
#endif
