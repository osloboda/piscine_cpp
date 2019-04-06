#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
private:
    unsigned int xp_;
    std::string type_;
public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria(AMateria const &);
    AMateria &operator=(AMateria const &);
    std::string const & getType() const; //Returns the materia type
    unsigned int getXP() const; //Returns the Materia's XP
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif