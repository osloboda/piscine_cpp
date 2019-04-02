/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:36:40 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/02 20:37:31 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

class FragTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);
		std::string get_name();
		int get_hit_point();
		int get_energy_point();
		int get_max_hit_point();
		int get_max_energy_point();
		int get_level();
		int get_Melee_attack_damage();
		int get_Ranged_attack_damage();
		int get_Armor_damage_reduction();

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
