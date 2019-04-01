/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:22 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:54:06 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		HumanA(std::string name);
		~HumanA();
		void setWeapon(Weapon &weapon);
		void attack(void);
	private:
		Weapon *_weapon;
		std::string _name;
};

#endif