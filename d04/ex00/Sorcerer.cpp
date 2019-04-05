/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:52:55 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/04 17:52:56 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(std::string name, std::string title): title(title), name(name)
{
    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer &D)
{
    *this = D;
    std::cout << this->name << ", " << this->title << ", is born !\n";
}

Sorcerer::Sorcerer()
{
    return ;
}

Sorcerer::~Sorcerer()
{
    std::cout << name << ", " << title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &Sorcerer::operator = (Sorcerer const &D)
{
    this->name = D.name;
    this->title = D.title;
    return *this;
}

const std::string &Sorcerer::getTitle() const
{
    return title;
}

const std::string &Sorcerer::getName() const
{
    return name;
}

void Sorcerer::polymorph(Victim const &D) const
{
    D.getPolymorphed();
}

std::ostream &operator << (std::ostream &os, Sorcerer const &D)
{
    return (os << "I am " << D.getName() << ", " << D.getTitle() << ", and I like ponies !\n");
}