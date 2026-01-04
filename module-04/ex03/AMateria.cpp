#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
    std::cout << "AMateria: default constructor has been called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria: public constructor has been called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
    std::cout << "AMateria: copy constructor has been called" << std::endl;
    this->type = other.type;
}

AMateria &AMateria::operator=(const AMateria &other) {
    std::cout << "AMateria: copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria: destructor has been called" << std::endl;
}

std::string const & AMateria::getType() const {
    return (this->type);
}


void AMateria::use(ICharacter& target) {
    (void)target;
}