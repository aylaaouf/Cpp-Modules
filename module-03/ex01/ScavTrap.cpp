#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap constructor has been called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor has been called" << std::endl; 
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoint == 0 || this->energyPoint == 0) {
        std::cout << "ScavTrap " << this->name << " cannot attack: no energy or hit points" << std::endl;
        return ;
    }
    this->energyPoint--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
        << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}