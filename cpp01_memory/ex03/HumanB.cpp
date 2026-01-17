#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : wb(NULL), name(name) { }

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    wb = &weapon;
}

void HumanB::attack() const {
    if (wb)
        std::cout << name << " attacks with their " << wb->getType() << "\n";
    else
        std::cout << name << " has no weapon to attack!\n";
}
