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

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &cp);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed& operator = (const Fixed &D);
	private:
		int fixed;
		const int fract = 8;
};

#endif
