#include "MutantStack.hpp"
#include <iostream>
int main() {
    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}