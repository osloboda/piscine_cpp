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

FragTrap::FragTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): name(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->max_hit_points = 100;
	this->max_energy_points = 100;
	this->Melee_attack_damage = 30;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	this->level = 1;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
}

int FragTrap::get_Armor_damage_reduction()
{
	return (this->Ranged_attack_damage);
}

int FragTrap::get_Melee_attack_damage()
{
	return (this->Melee_attack_damage);
}

int FragTrap::get_Ranged_attack_damage()
{
	return (this->Ranged_attack_damage);
}

int FragTrap::get_hit_point()
{
	return this->hit_points;
}

int FragTrap::get_energy_point()
{
	return this->energy_points;
}

int FragTrap::get_max_hit_point()
{
	return this->max_hit_points;
}

int FragTrap::get_level()
{
	return this->level;
}

int FragTrap::get_max_energy_point()
{
	return this->max_energy_points;
}

void FragTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP <" << this->get_name() << "> attacks <" << target << "> at range, causing <" << this->get_Ranged_attack_damage() << "> points of damage" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->get_name() << "> attacks <" << target << "> at range, causing <" << this->get_Melee_attack_damage() << "> points of damage" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	amount -= this->get_Armor_damage_reduction();
	if (this->get_hit_point() <= 0)
		std::cout << this->get_name() << " is dead." << std::endl;
	else if ((this->get_hit_point() < (int)amount))
	{
		this->hit_points = 0;
		std::cout << "FR4G-TP <" << this->get_name() << "> take damage <" << amount + this->get_Armor_damage_reduction() << std::endl << this->get_name() << " is dead." << std::endl;;
	}
	else
	{
		this->hit_points -= amount;
		std::cout << "FR4G-TP <" << this->get_name() << "> take damage <" << amount + this->get_Armor_damage_reduction() << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->get_hit_point() >= this->get_max_hit_point())
		std::cout << this->get_name() << " have maximum hit point" << std::endl;
	else
	{
		if ((this->get_hit_point() + (int)amount) > this->get_max_hit_point())
			this->hit_points = this->get_max_hit_point();
		else
			this->hit_points += amount;
		std::cout << "FR4G-TP <" << this->get_name() << "> is repaired by " << amount << "> Hit points" << std::endl;
	}
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->get_energy_point() < 25)
		std::cout << this->get_name() << " have not enough energy point" << std::endl;
	else
	{
		this->energy_points -= 25;
		std::string randomAttack[5] = {"Grandfather shotgun", "Blaster", "Desert Eagle", "Butter", ""};

		srand(time(NULL));
		std::cout << "FR4G-TP <" << this->get_name() << "> is attacking <" << target << "> with " << randomAttack[std::rand() % 5] << std::endl;
	}
}
