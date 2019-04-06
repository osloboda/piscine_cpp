#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
    public:
        Character(std::string const name);
        Character(Character const &);
        ~Character();
        Character &operator=(Character const &);
        std::string const &getName(void) const;
        void equip(AMateria *materia);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
    private:
        AMateria *slot[4];
        std::string	name;

};

#endif