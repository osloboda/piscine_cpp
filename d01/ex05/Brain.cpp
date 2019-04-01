/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:18:08 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:18:09 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain(void)
{
	std::stringstream   str;

	str << this;
	this->add = str.str();
	return ;
}

Brain::~Brain(void)
{
	return ;
}


std::string Brain:: identify(void)
{
	return (this->add);
}