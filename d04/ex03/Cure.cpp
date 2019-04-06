#include <iostream>
#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    return ;
}

Cure::Cure(Cure const &src): AMateria("cure")
{
    *this = src;
}

Cure::~Cure()
{
    return ;
};

Cure &Cure::operator=(Cure const &D)
{
    if (this != &D)
        AMateria::operator=(D);
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals bob's wounds *" << target.getName() << " *" << std::endl;
}