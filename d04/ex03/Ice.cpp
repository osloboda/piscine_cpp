#include <iostream>
#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
    return ;
}

Ice::Ice(Ice const &D) : AMateria(D)
{
    return ;
}

Ice::~Ice()
{
    return ;
};

Ice &Ice::operator = (Ice const &D)
{
    if (this != &D)
        AMateria::operator=(D);
    return (*this);
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName()<< " *" << std::endl;
}