#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap constructor has been called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor has been called" << std::endl; 
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name
        << " requests a positive high five!" << std::endl;
}