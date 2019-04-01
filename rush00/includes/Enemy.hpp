/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:24:20 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/29 21:24:45 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy
{
	public:
		Enemy(int row, int col);
		~Enemy();
		Enemy();
		void Print(std::string holst[130]);
		void Destroy(std::string holst[130]);
		int row;
		int col;
};

#endif
