/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:53:01 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/04 17:53:03 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <string>
#include "Victim.hpp"

class Sorcerer
{
    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer &D);
        ~Sorcerer();
        void introduce(void);
        Sorcerer &operator = (Sorcerer const &D);
        const std::string &getTitle() const;
        const std::string &getName() const;
        void polymorph(Victim const &) const;

    private:
        Sorcerer();
        std::string title;
        std::string name;
};

std::ostream &operator << (std::ostream &os, Sorcerer const &D);

#endif
