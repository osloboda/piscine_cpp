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

class Sorcerer
{
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
    private:
        std::string title;
        std::string name;
};

#endif
