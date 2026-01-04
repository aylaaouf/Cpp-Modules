#include "Ice.hpp"
#include <iostream>
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) {
    std::cout << "Ice: copy constructor has been called" << std::endl;
    this->type = other.type;
}

Ice &Ice::operator=(const Ice &other) {
    std::cout << "Ice: copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice: destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName()
        << " *" << std::endl;
}
