/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:49:13 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 14:49:17 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "FragTrap.hpp"

class ScavTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &);
		~ScavTrap();
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string get_name() const;
		int get_hit_point() const;
		int get_energy_point() const;
		int get_max_hit_point() const;
		int get_max_energy_point() const;
		int get_level() const;
		int get_Melee_attack_damage() const;
		int get_Ranged_attack_damage() const;
		int get_Armor_damage_reduction()const;
		void challengeNewcomer();
		ScavTrap& operator = (const ScavTrap &D);

	private:
		int hit_points;
		int max_hit_points;
		int energy_points;
		int max_energy_points;
		int level;
		int Melee_attack_damage;
		int Ranged_attack_damage;
		int Armor_damage_reduction;
		std::string name;
};

#endif