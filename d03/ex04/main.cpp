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
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(void)
{
	SuperTrap r5("Awesome");

	r5.meleeAttack("ohh myy");
    r5.rangedAttack("its works)");

    std::cout << r5.get_energy_point() << " " << r5.get_hit_point()<< std::endl;

	return (0);
}
