/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:53:21 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/04 17:53:28 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>

class Victim
{
    public:
        Victim(void);
        Victim(std::string name);
        Victim(Victim &copy);
        Victim &operator=(Victim const &rhs);
        ~Victim(void);
        std::string getName(void) const;
        void getPolymorphed() const;
    private:
        std::string name;
};

std::ostream &operator << (std::ostream &os, Victim const &obj);

#endif
