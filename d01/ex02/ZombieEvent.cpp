/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:59:03 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 17:59:30 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <string>
#include <cstdlib>

ZombieEvent::ZombieEvent(void)
{
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	return ;
}

void ZombieEvent:: setZombieType(std::string type)
{
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie;

	zombie = new Zombie(name, this->_type);
	return (zombie);
}

Zombie* ZombieEvent::randomChump(void)
{
	Zombie *zombie;
	std::string names[] = {"Maxim", "Dasha", "Bogdan", "Paul", "Yaroslav", "Tod", "Aleksey"};
	zombie = this->newZombie(names[(time(NULL) % 100) * 4 % 7]);
	zombie->announce();
	return (zombie);
}
