/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:30 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:54:20 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name, Weapon &weapon)
{
	HumanB::_name = name;
	HumanB::setWeapon(weapon);
	return ;
}

HumanB::HumanB(std::string name)
{
	HumanB::_name = name;
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::_weapon = &weapon;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	return ;
}
