#include "Animals.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog: constructor has been called" << std::endl;
    brain = new Brain();
    this->type = "Dog:";
}

Dog::Dog( const Dog& other ) {
    std::cout << "Dog: copy constructor has been called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog& Dog::operator=( const Dog& other ) {
    if (this != &other) {
        this->type = other.type;
        delete (this->brain);
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
    delete (brain);
}

void Dog::makeSound() const {
    std::cout << "Dog: Bark!" << std::endl;
}