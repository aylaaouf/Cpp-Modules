#include "Zombie.hpp"

int main() {
    Zombie *heapZ = newZombie("heap");
    heapZ->announce();
    delete (heapZ);

    randomChump("stack");
    return (0);
}