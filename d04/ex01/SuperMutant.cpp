#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !"
              << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &D): Enemy(D)
{
    std::cout << "Gaaah. Me want smash heads !"<< std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..."<< std::endl;
}

void		SuperMutant::takeDamage(int amount)
{
    hp -= amount / 3;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &D)
{
    Enemy::operator=(D);
    return *this;
}