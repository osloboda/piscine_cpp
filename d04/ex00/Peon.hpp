/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:52:40 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/04 17:52:47 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon(void);
        Peon(std::string name);
        Peon(Peon &copy);
        Peon &operator=(Peon const &rhs);
        ~Peon(void);
        void getPolymorphed(void) const;
};

#endif
