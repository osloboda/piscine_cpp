#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : name(name), damage(damage), apcost(apcost)
{
    return ;
}

AWeapon::AWeapon(void): name("?"), damage(0), apcost(0)
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
	this->damage = D.getDamage();
	this->apcost = D.getAPCost();
	this->name = D.getName();
    return *this;
}
