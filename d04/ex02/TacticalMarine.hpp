#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
public:
    TacticalMarine(void);
    virtual ~TacticalMarine();
    TacticalMarine(TacticalMarine const &D);
    TacticalMarine	&operator=(TacticalMarine const &D);

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif