#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Ana");
    ClapTrap b("Ana");

    std::cout << "----- ATTACK TEST -----" << std::endl;
    a.attack("Enemy");
    b.takeDamage(0);

    std::cout << "\n----- DAMAGE TEST -----" << std::endl;
    b.takeDamage(5);
    b.takeDamage(5);
    b.takeDamage(1);

    std::cout << "\n----- REPAIR TEST -----" << std::endl;
    a.takeDamage(3);
    a.beRepaired(2);
    a.beRepaired(5);

    std::cout << "\n----- ENERGY DEPLETION TEST -----" << std::endl;
    for (int i = 0; i < 11; i++)
        a.attack("Dummy");

    std::cout << "\n----- DEAD REPAIR TEST -----" << std::endl;
    b.beRepaired(4);

    return 0;
}
