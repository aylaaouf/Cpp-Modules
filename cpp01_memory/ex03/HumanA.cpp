#include "HumanA.hpp"

void HumanA::attack() const {
    std::cout << name << " attacks with their " << wa.getType() << "\n";
}

HumanA::HumanA(const std::string &name, Weapon &wa) : wa(wa), name(name) { }

HumanA::~HumanA() {};