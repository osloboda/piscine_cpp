/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:52:22 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/04 17:53:37 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog.\n";
}

Peon::Peon(Peon &D) : Victim(D) {
    *this = D;
}

Peon &Peon::operator=(Peon const &D) {
    Victim::operator=(D);
    std::cout << "Zog zog.\n";
    return *this;
}

Peon::~Peon(void) {
    std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed(void) const
{
    std::cout << this->getName() << " has been turned into a pink pony !\n";
}