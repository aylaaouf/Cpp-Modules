#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : name(""), hitPoint(10), energyPoint(10), attackDamage(0) {
        std::cout << "ClapTrap constructor has been called" << std::endl;
    }

ClapTrap::ClapTrap( std::string _name )
    : name(_name), hitPoint(10), energyPoint(10), attackDamage(0) {
        std::cout << "ClapTrap constructor has been called for " << name << std::endl;
    }

ClapTrap::ClapTrap( const ClapTrap& other) {
    *this = other;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoint = other.hitPoint;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target) {
    if (hitPoint == 0 || energyPoint == 0) {
        std::cout << "ClapTrap " << name << " cannot attack: no energy or hit points" << std::endl;
        return ;
    }
    energyPoint--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
        << attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoint == 0) {
        std::cout << "ClapTrap " << name << " is already dead" << std::endl;
        return ;
    }
    if (amount >= hitPoint)
        hitPoint = 0;
    else
        hitPoint -= amount;
    std::cout << "ClapTrap " << name << " took " << amount
        << " points of damage, HP now: " << hitPoint << std::endl;
    if(hitPoint == 0){
        std::cout <<  "ClapTrap " << name << " died" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoint == 0) {
        std::cout << "ClapTrap " << name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    if (energyPoint > 0) {
        hitPoint += amount;
        energyPoint--;
        std::cout << "ClapTrap " << name << " has been repaired by " <<
            amount << " points, HP now: " << hitPoint << std::endl;
    }
    else {
        std::cout << "ClapTrap " << name << " has no energy point to repair itself" <<
            std::endl;
    }
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor has been called" << std::endl;
}