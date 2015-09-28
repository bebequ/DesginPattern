#include "config.h"

#ifdef COMPOSITE

// Composite Pattern 
// 여러 오브젝트를 트리형식으로 묶을수 있음.
// RDC-DSP 구성을 이렇게 하면 되겠네요.

#include <vector>
#include <iostream> // std::cout
#include <memory> // std::auto_ptr
#include <algorithm> // std::for_each
#include <functional> // std::mem_fun

class Graphic {
public:
    virtual void print() const = 0;
    virtual ~Graphic() {}
};
 
class Ellipse : public Graphic {
public:
    void print() const {
        std::cout << "Ellipse \n";
    }
};
 
class CompositeGraphic : public Graphic {
public:
    void print() const {
        // for each element in graphicList_, call the print member function
        std::for_each(graphicList_.begin(), graphicList_.end(), std::mem_fun(&Graphic::print));
    }
 
    void add(Graphic *aGraphic) {
        graphicList_.push_back(aGraphic);
    }
 
private:
    std::vector<Graphic*>  graphicList_;
};

int main(int argc, char* argv[]) {

    // Initialize four ellipses
    const std::auto_ptr<Ellipse> ellipse1(new Ellipse());
    const std::auto_ptr<Ellipse> ellipse2(new Ellipse());
    const std::auto_ptr<Ellipse> ellipse3(new Ellipse());
    const std::auto_ptr<Ellipse> ellipse4(new Ellipse());

     // Initialize three composite graphics
    const std::auto_ptr<CompositeGraphic> graphic(new CompositeGraphic());
    const std::auto_ptr<CompositeGraphic> graphic1(new CompositeGraphic());
    const std::auto_ptr<CompositeGraphic> graphic2(new CompositeGraphic());
    
    // Composes the graphics
    graphic1->add(ellipse1.get());
    graphic1->add(ellipse2.get());
    graphic1->add(ellipse3.get());

    graphic2->add(ellipse4.get());

    graphic->add(graphic1.get());
    graphic->add(graphic2.get());

    // Prints the complete graphic (four times the string "Ellipses") 
    graphic->print();

    char c;
    std::cin >> c;
    return 0;
}
#endif
