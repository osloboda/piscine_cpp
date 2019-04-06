#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &);
        Ice &operator=(Ice const &);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter &target);
};

#endif