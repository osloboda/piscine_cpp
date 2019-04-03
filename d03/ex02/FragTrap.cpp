/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:36:15 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/02 20:36:32 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Inicial constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->max_hit_points = 100;
	this->max_energy_points = 100;
	this->Melee_attack_damage = 30;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	this->level = 1;
}

FragTrap::FragTrap(FragTrap const &D) : ClapTrap(D)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = D;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->get_energy_point() < 25)
		std::cout << this->get_name() << " have not enough energy point" << std::endl;
	else
	{
		this->energy_points -= 25;
		std::string funny_attacks[5] = {"Grandfather shotgun", "Blaster", "Desert Eagle", "His dog", "Bottle"};
		srand(time(NULL));
		std::cout << "FR4G-TP <" << this->get_name() << "> damaged <" << target << "> with " << funny_attacks[std::rand() % 5] << std::endl;
	}
}

FragTrap& FragTrap::operator = (const FragTrap &D)
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