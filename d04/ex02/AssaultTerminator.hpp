#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
public:
    AssaultTerminator(void);
    virtual ~AssaultTerminator();
    AssaultTerminator(AssaultTerminator const &D);
    AssaultTerminator	&operator=(AssaultTerminator const &D);

    ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};

#endif