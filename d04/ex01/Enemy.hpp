#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>
#include "AWeapon.hpp"

class Enemy
{
public:
    Enemy(void);
    Enemy(Enemy const &D);
    Enemy(int hp, std::string const &type);
    virtual ~Enemy(void);
    Enemy				&operator=(Enemy const &D);
    int					getHP() const;
    std::string	const	&getType(void) const;
    virtual void		takeDamage(int amount);
protected:
    int			hp;
    std::string	type;
};
#endif