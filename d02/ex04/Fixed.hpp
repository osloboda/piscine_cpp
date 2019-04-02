/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:57:04 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/01 17:03:14 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &cp);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed &operator=(const Fixed &D);
		Fixed operator+(const Fixed &D);
		Fixed operator-(const Fixed &D);
		Fixed operator*(const Fixed &D);
		Fixed operator/(const Fixed &D);
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed static const &max(Fixed const &D1, Fixed const &D2);
		Fixed static const &min(Fixed const &D1, Fixed const &D2);
	private:
		int fixed;
		const int fract;
};

std::ostream& operator << (std::ostream &out, Fixed const &value);
bool operator < (Fixed const &D1, Fixed const &D2);
bool operator > (Fixed const &D1, Fixed const &D2);
bool operator != (Fixed const &D1, Fixed const &D2);
bool operator == (Fixed const &D1, Fixed const &D2);
bool operator <= (Fixed const &D1, Fixed const &D2);
bool operator >= (Fixed const &D1, Fixed const &D2);

#endif
