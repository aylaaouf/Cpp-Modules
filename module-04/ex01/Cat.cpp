#include "Animals.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat: constructor has been called" << std::endl;
    brain = new Brain();
    this->type = "Cat";
};

Cat::Cat( const Cat& other ) {
    std::cout << "Cat: copy constructor has been called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat& Cat::operator=( const Cat& other ) {
    if (this != &other) {
        this->type = other.type;
        delete (brain);
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
    delete (brain);
};

void Cat::makeSound() const {
    std::cout << "Cat: meow!" << std::endl;
}