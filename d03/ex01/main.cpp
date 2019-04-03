/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:37:36 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/02 20:38:23 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap r1("Idiot");
	r1.meleeAttack("human");
	r1.rangedAttack("pelikan");
	r1.beRepaired(20);
	r1.takeDamage(40);
	r1.challengeNewcomer();
	r1.beRepaired(20);
	r1.takeDamage(100);
	r1.takeDamage(20);
	r1.beRepaired(100);
	r1.takeDamage(20);
	r1.challengeNewcomer();
	return (0);
}
