#include <iostream>
#include "Victim.hpp"

Victim::Victim(std::string name): name(name)
{
    std::cout << "Some random victim called " << name << " just popped !"<< std::endl;
}

Victim::Victim(Victim &D)
{
    *this = D;
    std::cout << "Some random victim called " << this->name << " just popped !"<< std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->name << " just died for no apparent reason !"<< std::endl;
}

Victim &Victim::operator = (Victim const &D)
{
    this->name = D.name;
    return *this;
}

std::string Victim::getName(void) const
{
    return name;
}

void Victim::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a cute little sheep !\n";
}

std::ostream &operator << (std::ostream &os, Victim const &D)
{
    return (os << "I am " << D.getName() << ", and I like otters !\n");
}