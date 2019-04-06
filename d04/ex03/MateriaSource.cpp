#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    this->count = 0;
}

MateriaSource::MateriaSource(MateriaSource const &D)
{
    *this = D;
}

MateriaSource::~MateriaSource() {}

void				MateriaSource::learnMateria(AMateria *materia)
{
    if (this->count < 4)
    {
        this->slot[this->count] = materia;
        this->count++;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &D)
{
    AMateria *tmp;
    if (this != &D)
        for (int i = 0; i < this->count; i++)
        {
            tmp = this->slot[i]->clone();
            delete this->slot[i];
            this->slot[i] = tmp;
        }
    return (*this);
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < this->count; i++)
        if (type == this->slot[i]->getType())
            return (this->slot[i]->clone());
    return (NULL);
}