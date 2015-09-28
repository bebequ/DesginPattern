#include "config.h"

#ifdef FLYWEIGHT

// Flywieght
//
//
//

#include <iostream>
#include <vector>

#define NUMBER_OF_SAME_TYPE_CHARS 3

class FlyweightCharacter;

class FlyweightCharacterAbstractBuilder {

    FlyweightCharacterAbstractBuilder() {}
    ~FlyweightCharacterAbstractBuilder() {}

public:
    static std::vector<float> fontSizes;
    static std::vector<std::string> fontNames;

    static void setFontsAndNames();
    static FlyweightCharacter createFlyweightCharacter(unsigned short fontSizeIndex,
                                                       unsigned short fontNameIndex,
                                                       unsigned short positionInStream);

};

std::vector<float> FlyweightCharacterAbstractBuilder::fontSizes(3);
std::vector<std::string> FlyweightCharacterAbstractBuilder::fontNames(3);
void FlyweightCharacterAbstractBuilder::setFontsAndNames() {
    fontSizes[0] = 1.0;
    fontSizes[1] = 1.5;
    fontSizes[2] = 2.0;

    fontNames[0] = "first_font";
    fontNames[1] = "seconed_font";
    fontNames[2] = "third_font";
}

FlyweightCharacter FlyweightCharacterAbstractBuilder::createFlyweightCharacter(unsigned short fontSizeIndex,
                                                                               unsigned short fontNameIndex,
                                                                               unsigned short positionInStream) {
    FlyweightCharacter fc(fontSizeIndex, fontNameIndex, positionInStream);
    return fc;
};

class FlyweightCharacter {

    unsigned short fontSizeIndex;
    unsigned short fontNameIndex;
    unsigned positionInStream;

public :
    FlyweightCharacter(unsigned short fontSizeIndex, 
                       unsigned short fontNameIndex, 
                       unsigned short positionInStream) 
        : fontSizeIndex(fontSizeIndex) 
        , fontNameIndex(fontNameIndex)
        , positionInStream(positionInStream) 
    {}

    void print() {
        std::string str =  FlyweightCharacterAbstractBuilder::fontNames[fontNameIndex];

        std::cout << "Font size: "   << FlyweightCharacterAbstractBuilder::fontSizes[fontSizeIndex] 
                  //<< ", font Name: " << FlyweightCharacterAbstractBuilder::fontNames[fontNameIndex]
                  << ", character stream postion: " << positionInStream 
                  << std::endl;
    }

    ~FlyweightCharacter() {}    

};

int main(int argc, char* argv[])  
{
    std::vector<FlyweightCharacter> chars;

    FlyweightCharacterAbstractBuilder::setFontsAndNames();
    unsigned short limit = NUMBER_OF_SAME_TYPE_CHARS;

    for (unsigned short i = 0; i < limit; i++ ) 
    {
        chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(0,0,i));
        chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(1,1,i+1*limit));
        chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(2,1,i+2*limit));
    }

    for (unsigned short i = 0; i < chars.size(); i++)
    {
        chars[i].print();
    }

    std::cin.get();
    return 0;
}
#endif
