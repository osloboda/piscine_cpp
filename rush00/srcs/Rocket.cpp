/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:07:05 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/29 19:07:58 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "../includes/galaxy.hpp"
#include "../includes/Rocket.hpp"

Rocket::Rocket()
{
	for (int i = 0; i < 50; i++)
	{
		enemyes[i] = Enemy(-10, -10);
	}
	for (int i = 0; i < 130; i++)
	{
		holst[i] = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ";
	}
	return ;
}

Rocket::~Rocket()
{
	return; ;
}

int Rocket::GetCol()
{
	return (this->_col);
}

int Rocket::GetRow()
{
	return (this->_row);
}

void Rocket::Destroy(void) {
	this->mutex.lock();
	attron(COLOR_PAIR(5));
	mvwprintw(stdscr, this->_row - 8, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 7, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 6, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 5, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 4, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 3, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 2, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row - 1, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	mvwprintw(stdscr, this->_row + 1, this->_col - 7, "^^^^^^^^^^^^^^^^^^^^^^");
	refresh();
	napms(200);
	clear();
	mvwprintw(stdscr, this->row / 2, this->col / 2 - 5, "You died(");
	attron(COLOR_PAIR(3));
	mvwprintw(stdscr, this->row / 2 + 2, this->col / 2 - 11, "Press R for restart...");
	refresh();
	while (true)
	{
		switch (getch()) {
			case 'r':
				this->_row = row;
				this->_col = col / 2 - 4;
				this->cul = this->_col;
				this->ruw = this->_row;
				for (int i = 0; i < 50; i++) {
					enemyes[i].col = -10;
					enemyes[i].row = -10;
				}
				for (int i = 0; i < 130; i++) {
					holst[i] = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ";
				}
				this->is_pause = 1;
				mutex.unlock();
				return ;
			case 27:
				//mutex.unlock();
				this->is_running = 0;
				this->is_pause = 0;
				return ;
			default:
				continue ;
		}
	}
}

void Rocket::Print(void)
{
	mmvwprintw(this->holst, this->_row - 7, this->_col, "                ");
	mmvwprintw(this->holst, this->_row - 6, this->_col, "                ");
	mmvwprintw(this->holst, this->_row - 5, this->_col, "      /");
	mmvwprintw(this->holst, this->_row - 5, this->_col + 6, "*");
	mmvwprintw(this->holst, this->_row - 5, this->_col + 7, "\\   ");
	mmvwprintw(this->holst, this->_row - 4, this->_col, "     | S.|   ");
	mmvwprintw(this->holst, this->_row - 3, this->_col, "     | B.|   ");
	mmvwprintw(this->holst, this->_row - 2, this->_col, "    /| D.|\\   ");
	mmvwprintw(this->holst, this->_row - 1, this->_col, "   /_| K.|_\\   ");
	mmvwprintw(this->holst, this->_row , this->_col, "                ");
	mmvwprintw(this->holst, this->_row + 1, this->_col, "                ");
}

void Rocket::SetPosition(int row, int col)
{
	this->_col = col;
	this->_row = row;
}