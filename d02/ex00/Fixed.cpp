/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:57:38 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/01 16:58:03 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixed(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &cp)
{
	*this = cp;
	std::cout << "Copy constructor called." << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->fixed = raw;
	return ;
}

Fixed& Fixed::operator = (const Fixed &D)
{
	std::cout << "Assignation operator called." << std::endl;
	this->fixed = D.getRawBits();
	return (*this);
}