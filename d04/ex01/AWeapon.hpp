#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>

class AWeapon
{
public:
    AWeapon(std::string const & name, int apcost, int damage);
    AWeapon(AWeapon const &);
    AWeapon();
    virtual ~AWeapon();
    std::string getName() const;
    int getAPCost() const;
    int getDamage() const;
    AWeapon &operator=(AWeapon const &);
    virtual void attack() const = 0;

protected:
    std::string name;
    int damage;
    int apcost;
};
#endif