/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:07:05 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/29 19:07:58 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROCKET_HPP
# define ROCKET_HPP

#include "Enemy.hpp"
#include "Bullet.hpp"
#include <string>
#include <mutex>

class Rocket
{
	public:
		Rocket();
		~Rocket();
		void SetPosition(int row, int col);
		void Print(void);
		void Destroy(void);
		int GetCol();
		int GetRow();
		int is_running;
		int is_shoot;
		int is_pause;
		int col;
		int row;
		int cul;
		int ruw;
		int kill;
		int best;
		int k, l, m;
		int moon;
		std::mutex mutex;
		std::string holst[130];
		Enemy enemyes[100];
		Bullet bullets[10];
	private:
		int _col;
		int _row;

};

#endif
