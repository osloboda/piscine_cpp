/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:05:00 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 18:06:52 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap();
		~NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &);
        void ninjaShoebox(NinjaTrap const &) const;
        void ninjaShoebox(ClapTrap const &) const;
        void ninjaShoebox(FragTrap const &) const;
        void ninjaShoebox(ScavTrap const &) const;
		NinjaTrap& operator = (const NinjaTrap &);
};

#endif
