/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:04:09 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 17:04:41 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>


Zombie::Zombie(std::string name, std::string type): _name(name), _type(type)
{
	return ;
}
Zombie::Zombie(void)
{
	return ;
}


Zombie::~Zombie(void)
{
	return ;
}

std::string Zombie:: get_name()
{
	return (this->_name);
}

std::string Zombie:: get_type()
{
	return (this->_type);
}

std::string get_tupe();

void Zombie:: announce()
{
		std::cout << "<" << this->_name << "(" << this->_type << ")> I'll eat you..." << std::endl;
}