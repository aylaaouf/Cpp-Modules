#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        Weapon &wa;
        std::string name;
    public:
        HumanA(const std::string &name, Weapon &wa);
        ~HumanA();
        void attack() const;
};

#endif