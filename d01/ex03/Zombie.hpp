/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:04:46 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 17:05:53 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie(std::string, std::string);
		Zombie();
		~Zombie(void);
		void announce();
		std::string get_name();
		std::string get_type();
	private:
	std::string _name;
	std::string _type;
};

#endif
