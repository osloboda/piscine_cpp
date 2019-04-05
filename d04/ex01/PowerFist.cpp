#include <string>
#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
    return ;
}

PowerFist::PowerFist(PowerFist const &D)
{
    *this = D;
}

PowerFist &PowerFist::operator=(PowerFist const &D)
{
    AWeapon::operator=(D);
    return *this;
}

PowerFist::~PowerFist()
{
    return;
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}