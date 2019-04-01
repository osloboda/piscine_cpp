/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:57:24 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:57:45 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name, Weapon &weapon);
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack(void);
	private:
		Weapon *_weapon;
		std::string _name;
};

#endif
