#include "Animals.hpp"
#include <iostream>

WrongCat::WrongCat() {
    std::cout << "Cat: constructor has been called" << std::endl;
    this->type = "Cat";
}

WrongCat::WrongCat( const WrongCat& other ) {
    std::cout << "Cat: copy constructor has been called" << std::endl;
    this->type = other.type;
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
    if (this != &other) { this->type = other.type; }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "Cat: Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Cat: meow!" << std::endl;
}