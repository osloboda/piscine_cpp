#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
public:
    Squad();
    virtual ~Squad();
    Squad(Squad const &);
    int getCount() const;
    ISpaceMarine* getUnit(int) const;
    Squad &operator = (Squad const &);
    int push(ISpaceMarine*);
private:
    int				count;
    ISpaceMarine	**units;
};

#endif