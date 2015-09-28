#include "config.h"

#include "config.h"

#ifdef SINGLETON
#include <iostream>

class SingleObject {
private:
    SingleObject() {};
    SingleObject(const SingleObject &o);
    static SingleObject* pInstance;

protected:

public:
    static SingleObject& getInstance() {

        if(pInstance == NULL) pInstance = new SingleObject;
        return *pInstance;
    }

    static SingleObject* getInstancePtr() {
        
        if(pInstance == NULL) pInstance = new SingleObject;
        return pInstance;
    }

    void show() {
        std::cout<< "SingleOjbect::show()." <<std::endl;
    }
    
};

SingleObject* SingleObject::pInstance = NULL;

int main(int argc,char* argv[])
{
    std::cout<< "main()" <<std::endl;

    SingleObject::getInstance().show();
    //pSingleton.show();

    char c ;
    std::cin >> c;

    return 0;
}
#endif
