/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:10:00 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 17:10:02 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name)
{
	std::cout << "ClapTrap Inicial constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->max_hit_points = 100;
	this->max_energy_points = 100;
	this->Melee_attack_damage = 30;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	this->level = 1;
}

ClapTrap::ClapTrap(ClapTrap const &D)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = D;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}


int ClapTrap::get_Armor_damage_reduction() const
{
	return (this->Armor_damage_reduction);
}

int ClapTrap::get_Melee_attack_damage() const
{
	return (this->Melee_attack_damage);
}

int ClapTrap::get_Ranged_attack_damage() const
{
	return (this->Ranged_attack_damage);
}

int ClapTrap::get_hit_point() const
{
	return this->hit_points;
}

int ClapTrap::get_energy_point() const
{
	return this->energy_points;
}

int ClapTrap::get_max_hit_point() const
{
	return this->max_hit_points;
}

int ClapTrap::get_level() const
{
	return this->level;
}

int ClapTrap::get_max_energy_point() const
{
	return this->max_energy_points;
}

std::string ClapTrap::get_name() const
{
	return this->name;
}

void ClapTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP <" << this->get_name() << "> attacks <" << target << "> at range, causing <" << this->get_Ranged_attack_damage() << "> points of damage" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->get_name() << "> attacks <" << target << "> at range, causing <" << this->get_Melee_attack_damage() << "> points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	amount -= this->get_Armor_damage_reduction();
	if (this->get_hit_point() <= 0)
		std::cout << "FR4G-TP <"<< this->get_name() << "> is dead." << std::endl;
	else if ((this->get_hit_point() <= (int)amount))
	{
		this->hit_points = 0;
		std::cout << "FR4G-TP <" << this->get_name() << "> take damage <" << amount + this->get_Armor_damage_reduction() << ">" << std::endl << "FR4G-TP <"<< this->get_name() << "> is dead." << std::endl;;
	}
	else
	{
		this->hit_points -= amount;
		std::cout << "FR4G-TP <" << this->get_name() << "> take damage <" << amount + this->get_Armor_damage_reduction() << ">" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->get_hit_point() >= this->get_max_hit_point())
		std::cout << "FR4G-TP <" << this->get_name() << "> have maximum hit point" << std::endl;
	else
	{
		if ((this->get_hit_point() + (int)amount) > this->get_max_hit_point())
			this->hit_points = this->get_max_hit_point();
		else
			this->hit_points += amount;
		std::cout << "FR4G-TP <" << this->get_name() << "> repaired by <" << amount << "> Hit points" << std::endl;
	}
}

ClapTrap& ClapTrap::operator = (const ClapTrap &D)
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