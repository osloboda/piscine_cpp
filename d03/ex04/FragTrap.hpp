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

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &);
		void vaulthunter_dot_exe(std::string const & target);
		FragTrap& operator = (const FragTrap &);

	protected:
		int energy_points;
		int max_energy_points;
		int Melee_attack_damage;
};

#endif
