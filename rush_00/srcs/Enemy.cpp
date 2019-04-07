/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:25:01 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/29 21:25:03 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.hpp"
#include <curses.h>
#include "../includes/galaxy.hpp"

Enemy::Enemy(int row, int col):row(row), col(col)
{
	this->bullet = Bullet(row, col);
	return ;
}

Enemy::Enemy()
{
	return ;
}

Enemy::~Enemy(void)
{
	return ;
}

void Enemy::Destroy(std::string holst[130])
{
	mmvwprintw(holst, this->row, this->col, " <#####>   ");
	mmvwprintw(holst, this->row, this->col, " <#####>   ");
	mmvwprintw(holst, this->row + 1, this->col, "<#######>  ");
	mmvwprintw(holst, this->row + 2, this->col, " <_____>   ");
	napms(50);

	mmvwprintw(holst, this->row, this->col, "           ");
	mmvwprintw(holst, this->row, this->col, "           ");
	mmvwprintw(holst, this->row + 1, this->col, "           ");
	mmvwprintw(holst, this->row + 2, this->col, "           ");
	mmvwprintw(holst, this->row + 3, this->col, "           ");
	mmvwprintw(holst, this->row + 4, this->col, "           ");
}

void Enemy::Print(std::string holst[130])
{
	mmvwprintw(holst, this->row, this->col, " /(_M_)\\ ");
	mmvwprintw(holst, this->row, this->col, " /(_M_)\\ ");
	mmvwprintw(holst, this->row + 1, this->col, "|       |");
	mmvwprintw(holst, this->row + 2, this->col, " \\/~V~\\/");
}