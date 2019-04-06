/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:12:36 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 21:13:34 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class SuperTrap: public FragTrap, public NinjaTrap
{
    public:
        SuperTrap();
        ~SuperTrap();
        SuperTrap(std::string name);
        SuperTrap(SuperTrap const &);
        SuperTrap& operator = (const SuperTrap &);
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
};

#endif
