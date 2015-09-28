#include "config.h"

#ifdef ADAPTER
#include <iostream>

// Adapter Pattern
// 함수리스트나 파라메터가 틀릴때, 껍데기 씌여서 이빨 맞추는 기법

class Muslim {
public:
    virtual ~Muslim() {};
    virtual void performsMuslimRitual() = 0;
};

class MuslimFemale : public Muslim {
public:
    // 여기서 override는 방지용이다.
    virtual void performsMuslimRitual() override {
        std::cout << "Muslim girl performs Muslim ritual." <<std::endl;
    }
};

class Hindu {
public:
    virtual ~Hindu() {};
    virtual void performHinduRitural()=0;
};

class HinduFemale : public Hindu {
public:
    virtual void performHinduRitural() override {
        std::cout << "Hindu girl performs Hindu ritual." << std::endl;
    }
};

class MuslimRitual {
public:
    void carrayOutRitual(Muslim* muslim) {
        std::cout<<"On with the Muslim rituals!" << std::endl;
        muslim->performsMuslimRitual();
    }
};

class MuslimAdapter :public Muslim {
private:
    Hindu* hindu;
public:
    MuslimAdapter (Hindu *h) : hindu(h) {}
    virtual void performsMuslimRitual() override {
        hindu->performHinduRitural();
    }
};

int main(int argc, char* argv[])
{
    HinduFemale* hinduGirl = new HinduFemale;
    MuslimFemale* muslimGirl = new MuslimFemale;
    MuslimRitual muslimRitual;
    //muslimRitual.carrayOutRitual(hinduGirl);

    MuslimAdapter * adapterHindu = new MuslimAdapter(hinduGirl);
    muslimRitual.carrayOutRitual(muslimGirl);
    muslimRitual.carrayOutRitual(adapterHindu);

    char c;
    std::cin >> c;

    return 0;
}
#endif
