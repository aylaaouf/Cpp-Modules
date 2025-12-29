#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("default"), 
      ScavTrap(), 
      FragTrap() 
{
    this->name = "default";
    this->hitPoint = FragTrap::hitPoint;
    this->energyPoint = ScavTrap::energyPoint;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name) {
        this->name = name;
        this->hitPoint = FragTrap::hitPoint;
        this->energyPoint = ScavTrap::energyPoint;
        this->attackDamage = FragTrap::attackDamage;
        std::cout << "DiamondTrap constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other) 
{
    *this = other;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called for " << this->name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap name: " << this->name << std::endl;
    std::cout << "I am ClapTrap name: " << ClapTrap::name << std::endl;
}