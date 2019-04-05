#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : name(name), apcost(apcost), damage(damage)
{
    return ;
}

AWeapon::AWeapon(void): name("?"), apcost(0), damage(0)
{
    return ;
}

AWeapon::~AWeapon()
{
    return ;
}

AWeapon::AWeapon(AWeapon const &D)
{
    *this = D;
}

std::string AWeapon::getName() const
{
    return this->name;
}

int AWeapon::getAPCost() const
{
    return this->apcost;
}

int AWeapon::getDamage() const
{
    return this->damage;
}

AWeapon &AWeapon::operator=(AWeapon const &D)
{
    return *this;
}
