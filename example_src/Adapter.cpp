#include "config.h"

#ifdef ADAPTER
#include <iostream>

// Adapter Pattern
// �Լ�����Ʈ�� �Ķ���Ͱ� Ʋ����, ������ ������ �̻� ���ߴ� ���

class Muslim {
public:
    virtual ~Muslim() {};
    virtual void performsMuslimRitual() = 0;
};

class MuslimFemale : public Muslim {
public:
    // ���⼭ override�� �������̴�.
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
