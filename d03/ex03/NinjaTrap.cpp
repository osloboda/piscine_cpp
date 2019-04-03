/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:04:51 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 18:04:56 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(): ClapTrap()
{
	std::cout << "NinjaTrap Default constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	std::cout << "NinjaTrap Inicial constructor called" << std::endl;
	this->hit_points = 60;
	this->energy_points = 120;
	this->max_hit_points = 60;
	this->max_energy_points = 120;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage = 5;
	this->Armor_damage_reduction = 0;
	this->level = 1;
}

NinjaTrap::NinjaTrap(NinjaTrap const &D) : ClapTrap(D)
{
	std::cout << "NinjaTrap Copy constructor called" << std::endl;
	*this = D;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap Destructor called" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap const &D) const
{
    std::cout << "Ninja detect ClapTrap <" << D.get_name() << ">\n";
}

void NinjaTrap::ninjaShoebox(FragTrap const &D) const
{
    std::cout << "Ninja detect FragTrap <" << D.get_name() << ">\n";
}

void NinjaTrap::ninjaShoebox(ScavTrap const &D) const
{
    std::cout << "Ninja detect ScavTrap <" << D.get_name() << ">\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap const &D) const
{
    std::cout << "Ninja detect NinjaTrap <" << D.get_name() << ">\n";
}

NinjaTrap& NinjaTrap::operator = (const NinjaTrap &D)
{
	this->hit_points = D.get_hit_point();
	this->energy_points = D.get_energy_point();
	this->level = D.get_level();
	this->name = D.get_name();
	this->Melee_attack_damage = D.get_Melee_attack_damage();
	this->Ranged_attack_damage = D.get_Ranged_attack_damage();
	this->Armor_damage_reduction = D.get_Armor_damage_reduction();
	return (*this);
}