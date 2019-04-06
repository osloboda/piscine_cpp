#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(std::string const &type): xp_(0), type_(type)
{
    return ;
}

AMateria::AMateria(AMateria const &D)
{
    *this = D;
}

AMateria::~AMateria(void)
{}

std::string const& AMateria::getType() const
{
    return this->type_;
}

unsigned int AMateria::getXP() const
{
    return this->xp_;
}

AMateria &AMateria::operator=(AMateria const &D)
{
    if (this != &D)
    {
        this->type_ = D.getType();
        this->xp_ = D.getXP();
    }
    return (*this);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}
