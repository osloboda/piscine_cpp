#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
    SuperMutant();
    virtual ~SuperMutant();
    SuperMutant(SuperMutant const &);
    SuperMutant &operator = (SuperMutant const &);
    virtual void takeDamage(int amount);
};

#endif