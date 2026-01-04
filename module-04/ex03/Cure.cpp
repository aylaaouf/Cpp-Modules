#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) {
    std::cout << "Cure: copy constructor has been called" << std::endl;
    this->type = other.type;
}

Cure &Cure::operator=(const Cure &other) {
    std::cout << "Cure: copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure: destructor called" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName()
        << "'s wounds *" << std::endl;
}
