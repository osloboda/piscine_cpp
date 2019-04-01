/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:06:03 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 18:01:20 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <string>
#include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int N);
		ZombieHorde();
		~ZombieHorde();
		void setZombieType(std::string type);
		Zombie* newZombie(std::string name);
		Zombie* randomChump(void);
		void announce();

	private:
		std::string  _type;
		Zombie *_zombies;
		int _n;
};


#endif
