#include "Zombie.hpp"

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string n) {
    name = n;
}

Zombie::~Zombie() {
    std::cout << name << ": Zombie destroyed!\n";
}
