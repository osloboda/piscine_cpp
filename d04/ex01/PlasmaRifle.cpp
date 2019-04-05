#include <string>
#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
    return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &D)
{
    *this = D;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &D)
{
    AWeapon::operator=(D);
    return *this;
}
PlasmaRifle::~PlasmaRifle()
{
    return;
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}