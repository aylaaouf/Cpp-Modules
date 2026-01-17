#include "Animals.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal constructor has been called" << std::endl;
    this->type = "fake";
}

Animal::Animal( const Animal& other ) {
    std::cout << "Animal copy constructor has been called" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=( const Animal& other ) {
    if (this != &other) { this->type = other.type; }
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
};

std::string Animal::getType() const {
    return (this->type);
}
