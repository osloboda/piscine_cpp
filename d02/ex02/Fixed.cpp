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
#include <cmath>

Fixed::Fixed() : fixed(0), fract(8)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}
Fixed::Fixed(const int i) : fixed(0), fract(8)
{
	std::cout << "Int constructor called." << std::endl;
	this->setRawBits(i << this->fract);
	return ;
}

Fixed::Fixed(const float i) : fixed(0), fract(8)
{
	std::cout << "Float constructor called." << std::endl;
	this->setRawBits(roundf(i * 256));
	return ;
}

Fixed::Fixed(const Fixed &cp) : fixed(0), fract(8)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = cp;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / 256);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->fract);
}

int Fixed::getRawBits() const
{
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
	return ;
}

Fixed& Fixed::operator = (const Fixed &D)
{
	std::cout << "Assignation operator called." << std::endl;
	this->fixed = D.getRawBits();
	return (*this);
}

Fixed Fixed::operator * (const Fixed &D)
{
	return (Fixed(this->toFloat() * D.toFloat()));
}

Fixed Fixed::operator + (const Fixed &D)
{
	return (Fixed(this->toFloat() + D.toFloat()));
}

Fixed Fixed::operator - (const Fixed &D)
{
	return (Fixed(this->toFloat() - D.toFloat()));
}

Fixed Fixed::operator / (const Fixed &D)
{
	return (Fixed(this->toFloat() / D.toFloat()));
}

Fixed& Fixed::operator ++ (void)
{
	this->fixed += 1;
	return (*this);
}

Fixed& Fixed::operator -- (void)
{
	this->fixed -= 1;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed tmp = Fixed(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator -- (int)
{
	Fixed tmp = Fixed(*this);
	operator--();
	return (tmp);
}

Fixed const &Fixed::max(Fixed const &D1, Fixed const &D2)
{
	if (D1.toFloat() >= D2.toFloat())
		return (D1);
	else
		return (D2);
}

Fixed const &Fixed::min(Fixed const &D1, Fixed const &D2)
{
	if (D1.toFloat() <= D2.toFloat())
		return (D1);
	else
		return (D2);
}

bool operator < (Fixed const &D1, Fixed const &D2)
{
	return (D1.toFloat() < D2.toFloat());
}

bool operator > (Fixed const &D1, Fixed const &D2)
{
	return (D1.toFloat() > D2.toFloat());
}

bool operator != (Fixed const &D1, Fixed const &D2)
{
	return (D1.toFloat() != D2.toFloat());
}

bool operator == (Fixed const &D1, Fixed const &D2)
{
	return (D1.toFloat() == D2.toFloat());
}

bool operator >= (Fixed const &D1, Fixed const &D2)
{
	return (D1.toFloat() >= D2.toFloat());
}

bool operator <= (Fixed const &D1, Fixed const &D2)
{
	return (D1.toFloat() <= D2.toFloat());
}

std::ostream& operator << (std::ostream &out, Fixed const &value)
{
	return(out << value.toFloat());
}