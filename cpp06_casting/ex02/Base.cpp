#include "Base.hpp"

Base* generate(void) {
    int r = rand() % 3;
    std::cout << r<< std::endl;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "type of object: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "type of object: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "type of object: C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "type of object: A" << std::endl;
        return;
    } catch (...) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "type of object: B" << std::endl;
        return;
    } catch (...) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "type of object: C" << std::endl;
        return;
    } catch (...) {}
}

Base::~Base() {}