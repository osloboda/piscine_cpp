/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:13:38 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 21:13:41 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap()
{
    std::cout << "SuperTrap Default constructor called" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap(name)
{
    std::cout << "SuperTrap Inicial constructor called" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &D) : ClapTrap(D)
{
    std::cout << "SuperTrap Copy constructor called" << std::endl;
    *this = D;
}

SuperTrap::~SuperTrap()
{
    std::cout << "SuperTrap Destructor called" << std::endl;
}

void SuperTrap::rangedAttack(std::string const &target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
    NinjaTrap::meleeAttack(target);
}

SuperTrap& SuperTrap::operator = (const SuperTrap &D)
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