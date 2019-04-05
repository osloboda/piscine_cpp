#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include <string>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    PowerFist(PowerFist const &);
    virtual ~PowerFist();
    PowerFist &operator = (PowerFist const &);
    virtual void attack(void) const;
};
#endif