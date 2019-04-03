/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:49:22 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 14:49:25 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): name(name)
{
	std::cout << "Inicial constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->max_hit_points = 100;
	this->max_energy_points = 50;
	this->Melee_attack_damage = 20;
	this->Ranged_attack_damage = 15;
	this->Armor_damage_reduction = 3;
	this->level = 1;
}

ScavTrap::ScavTrap(ScavTrap const &D)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = D;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
}

int ScavTrap::get_Armor_damage_reduction() const
{
	return (this->Armor_damage_reduction);
}

int ScavTrap::get_Melee_attack_damage() const
{
	return (this->Melee_attack_damage);
}

int ScavTrap::get_Ranged_attack_damage() const
{
	return (this->Ranged_attack_damage);
}

int ScavTrap::get_hit_point() const
{
	return this->hit_points;
}

int ScavTrap::get_energy_point() const
{
	return this->energy_points;
}

int ScavTrap::get_max_hit_point() const
{
	return this->max_hit_points;
}

int ScavTrap::get_level() const
{
	return this->level;
}

int ScavTrap::get_max_energy_point() const
{
	return this->max_energy_points;
}

std::string ScavTrap::get_name() const
{
	return this->name;
}

void ScavTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP <" << this->get_name() << "> attacks <" << target << "> at range, causing <" << this->get_Ranged_attack_damage() << "> points of damage" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->get_name() << "> attacks <" << target << "> at range, causing <" << this->get_Melee_attack_damage() << "> points of damage" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
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

void ScavTrap::beRepaired(unsigned int amount)
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

void ScavTrap::challengeNewcomer(void)
{
	std::string funny_challenges[5] = {"Do you want some tea?", "Let's see how you make friends with my hand spider.", "Welcome to the hell)", "Come in, but i live with sixteen big snakes:)", "Do you really want to know what is behind that door?"};
	srand(time(NULL));
	std::cout << funny_challenges[std::rand() % 5] << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &D)
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