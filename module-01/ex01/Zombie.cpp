#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << this->name << ": destroyed!\n";
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}