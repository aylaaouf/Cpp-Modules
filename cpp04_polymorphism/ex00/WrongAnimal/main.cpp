#include "Animals.hpp"
#include <iostream>

int main()
{
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete (i);
    delete (meta);
    return (0);
}