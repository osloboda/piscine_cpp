#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <string>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        PlasmaRifle();
        PlasmaRifle(PlasmaRifle const &);
        virtual ~PlasmaRifle();
        PlasmaRifle &operator = (PlasmaRifle const &);
        virtual void attack(void) const;
};
#endif