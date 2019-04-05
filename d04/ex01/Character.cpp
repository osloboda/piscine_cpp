#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name) : name(name)
{
        this->AP = 40;
        this->Weapon = NULL;
}

Character::Character(Character const &D)
{
    *this = D;
}

Character::~Character()
{
    return ;
}

void Character::recoverAP()
{
    this->AP += 10;

    if (this->AP > 40)
        this->AP = 40;
}

std::string Character::getName() const
{
    return this->name;
}

int Character::getAP() const
{
    return this->AP;
}

void Character::equip(AWeapon *D)
{
    this->Weapon = D;
}

AWeapon* Character::getWeapon() const
{
    return this->Weapon;
}

void Character::attack(Enemy *D)
{
    if (this->Weapon)
    {
        if (this->Weapon->getAPCost() > this->AP)
            std::cout << "" << std::endl;
        else
        {
            std::cout << this->getName() << " attacks " << D->getType() << " with a " << this->Weapon->getName() << std::endl;
            D->takeDamage(this->Weapon->getDamage());
            this->AP -= this->Weapon->getAPCost();
            this->Weapon->attack();
            if (this->AP < 0)
                this->AP = 0;
            if (D->getHP() <= 0)
                delete (D);
        }
    }
}

std::ostream &operator << (std::ostream &os, Character const &D)
{
    if (D.getWeapon())
        return (os << D.getName() << " has " << D.getAP() << " AP and wields a " << D.getWeapon()->getName() << "\n");
    return (os << D.getName() << " has " << D.getAP() << " AP and is unarmed" << "\n");
}
