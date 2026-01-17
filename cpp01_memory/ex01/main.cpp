#include "Zombie.hpp"

int main() {
    Zombie *z = zombieHorde(6, "zombieHorde");

    for (int i = 0; i < 6; i++)
        z[i].announce();
    delete[] (z);
}