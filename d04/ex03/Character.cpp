#include <string>
#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character(const std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    return ;
}

Character::Character(Character const &D)
{
    *this = D;
}

Character::~Character()
{
    return ;
}

std::string const& Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *materia)
{
    int i;
    for(i = 0; i < 4 && this->slot[i];)
        i++;
    if (i < 4)
        this->slot[i] = materia;
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
        this->slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    AMateria *tmp;

    tmp = this->slot[idx];
    if (tmp)
        tmp->use(target);
}

Character &Character::operator=(Character const &D)
{
    int				i;
    AMateria		*tmp;

    if (this != &D)
    {
        i = 0;
        for (int i = 0; i < 4;i++)
            if (this->slot[i])
            {
                tmp = this->slot[i]->clone();
                if (this->slot[i])
                    delete this->slot[i];
                this->slot[i] = tmp;
            }
        this->name = D.name;
    }
    return (*this);
}