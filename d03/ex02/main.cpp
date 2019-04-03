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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap r1("Idiot");
	ClapTrap r2("Idiot2");
	ScavTrap r3("idiot3");

	r1.meleeAttack("human");
	r1.rangedAttack("pelikan");
	r1.beRepaired(20);
	r1.takeDamage(40);
	r1.beRepaired(20);
	r1.takeDamage(100);
	r1.takeDamage(20);
	r1.beRepaired(100);
	r1.takeDamage(20);
	r1.vaulthunter_dot_exe("hohoho");

	r2.meleeAttack("human");
	r2.rangedAttack("pelikan");
	r2.takeDamage(40);
	r2.beRepaired(20);
	r2.beRepaired(20);
	r2.takeDamage(100);
	r2.takeDamage(20);
	r2.beRepaired(100);
	r2.takeDamage(20);

	r3.meleeAttack("human");
	r3.rangedAttack("pelikan");
	r3.takeDamage(40);
	r3.beRepaired(20);
	r3.beRepaired(20);
	r3.takeDamage(100);
	r3.takeDamage(20);
	r3.beRepaired(100);
	r3.takeDamage(20);
	r3.challengeNewcomer();
	return (0);
}
