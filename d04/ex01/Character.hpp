#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
public:
    Character(std::string const & name);
    ~Character();
    Character(Character const &);
    void recoverAP();
    void equip(AWeapon*);
    void attack(Enemy*);
    std::string getName() const;
    int getAP() const;
    AWeapon *getWeapon() const;

private:
    std::string name;
    int AP;
    AWeapon *Weapon;
};

std::ostream &operator << (std::ostream &os, Character const &D);

#endif