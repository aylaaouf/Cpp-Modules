#include "Animals.hpp"
#include <iostream>

int main() {
    Animal* cat = new Cat();
    Animal* dog = new Dog();

    cat->makeSound();
    dog->makeSound();
    delete (cat);
    delete (dog);
    return (0);
}