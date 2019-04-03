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

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap Inicial constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->max_hit_points = 100;
	this->max_energy_points = 50;
	this->Melee_attack_damage = 20;
	this->Ranged_attack_damage = 15;
	this->Armor_damage_reduction = 3;
	this->level = 1;
}

ScavTrap::ScavTrap(ScavTrap const &D): ClapTrap(D)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = D;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::challengeNewcomer()
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