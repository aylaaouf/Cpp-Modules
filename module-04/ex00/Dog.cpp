#include "Animals.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog: constructor has been called" << std::endl;
    this->type = "Dog:";
};

Dog::Dog( const Dog& other ) {
    std::cout << "Dog: copy constructor has been called" << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=( const Dog& other ) {
    if (this != &other) { this->type = other.type; }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "Dog: Bark!" << std::endl;
}