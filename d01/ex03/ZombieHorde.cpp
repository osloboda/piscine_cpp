/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:59:03 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 18:47:28 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>

ZombieHorde::ZombieHorde(int N):_n(N)
{
	if (N < 1 || N > INT_MAX)
	{
		std::cout << "Incorrect N!" << std::endl;
		return ;
	}
	this->_zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		this->setZombieType("idiot");
		this->_zombies[i] = *this->randomChump();
	}
	return ;
}

ZombieHorde::ZombieHorde(void)
{
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	return ;
}

void ZombieHorde:: announce()
{
	int i = 0;

	while (i < this->_n)
	{
		this->_zombies[i].announce();
		i++;
	}
}

void ZombieHorde:: setZombieType(std::string type)
{
	this->_type = type;
}

Zombie* ZombieHorde::newZombie(std::string name)
{
	Zombie *zombie;

	zombie = new Zombie(name, this->_type);
	return (zombie);
}

Zombie* ZombieHorde::randomChump(void)
{
	Zombie *zombie;
	std::string names[] = {"Maxim", "Dasha", "Bogdan", "Paul", "Yaroslav", "Tod", "Aleksey"};

	unsigned i = rand() % 7;
	zombie = this->newZombie(names[i]);
	return (zombie);
}
