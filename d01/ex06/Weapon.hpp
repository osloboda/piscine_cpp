/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:51 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:54:48 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(const std::string &type);
		Weapon();
		~Weapon();
		const std::string &getType() const;
		void setType(const std::string &type);
	private:
		std::string _type;
};

#endif
