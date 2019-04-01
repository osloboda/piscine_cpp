/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:59:36 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 18:01:04 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	srand(time(NULL));
	rand();
	rand();
	ZombieHorde *zombieHorde;
	zombieHorde = new ZombieHorde(10);
	zombieHorde->announce();
	delete (zombieHorde);
	return (0);
}
