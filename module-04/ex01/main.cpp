#include "Animals.hpp"
#include <iostream>

int main() {
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++) animals[i] = new Dog();
    for (int i = size / 2; i < size; i++) animals[i] = new Cat();

    for (int i = 0; i < size; i++) animals[i]->makeSound();

    for (int i = 0; i < size; i++) delete animals[i];

    return (0);
}