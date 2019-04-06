#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type): hp(hp), type(type)
{
    return ;
}

Enemy::Enemy(void): hp(0), type("?")
{
    return ;
}

Enemy::~Enemy()
{
    return ;
}

Enemy::Enemy(Enemy const &D)
{
    *this = D;
}

Enemy &Enemy::operator=(Enemy const &D)
{
    this->hp = D.getHP();
    this->type = D.getType();
    return *this;
}

int Enemy::getHP() const
{
    return this->hp;
}

std::string	const& Enemy::getType() const
{
    return this->type;
}

void Enemy::takeDamage(int amount)
{
    if (amount >= 0)
    {
        this->hp -= amount;
        if (this->hp < 0)
            this->hp = 0;
    }
}