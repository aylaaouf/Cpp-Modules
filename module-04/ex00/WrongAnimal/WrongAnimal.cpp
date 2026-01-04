#include "Animals.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << "Animal constructor has been called" << std::endl;
    this->type = "fake";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
    std::cout << "Animal copy constructor has been called" << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
    if (this != &other) { this->type = other.type; }
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}

void WrongAnimal::makeSound() const {
    std::cout << "Animal: fake sound" << std::endl;
}