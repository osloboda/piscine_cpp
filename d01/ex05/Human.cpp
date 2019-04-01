/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:18:29 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:18:30 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	return ;
}

Human::~Human(void)
{
	return ;
}
Brain Human:: getBrain(void)
{
	return (this->_brain);
}

std::string Human:: identify(void)
{
	return (this->_brain.identify());
}