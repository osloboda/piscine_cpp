#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    int					count;
    AMateria			*slot[4];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(MateriaSource const &);
    MateriaSource &operator = (MateriaSource const &);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif