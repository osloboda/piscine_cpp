/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:10 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:54:10 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	HumanA::_name = name;
	HumanA::setWeapon(weapon);
	return ;
}

HumanA::HumanA(std::string name)
{
	HumanA::_name = name;
	return ;
}

HumanA::~HumanA(void)
{
	HumanA::_name = "";
	return ;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	return ;
}