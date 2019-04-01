/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:59:36 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 18:00:03 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Zombie *zombie;
	ZombieEvent zombieEvent;
	zombie = new Zombie("s", "n");
	zombie->announce();
	delete(zombie);

	zombieEvent.setZombieType("idiot");
	zombie = zombieEvent.newZombie("Max");
	zombie->announce();
	delete(zombie);

	zombieEvent.setZombieType("human");
	zombie = zombieEvent.randomChump();
	delete(zombie);
	return (0);
}
