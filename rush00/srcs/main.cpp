/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:54:35 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/29 16:54:49 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/galaxy.hpp"
#include <iostream>
#include <curses.h>
#include <thread>
#include <chrono>
#include <cstring>
#include <ncurses.h>
#include <string>
#include "../includes/Enemy.hpp"
#include <mutex>


void	mmvwprintw(std::string holst[130], int row, int col, const char *str)
{

	holst[row + 10].replace(col + 20 , strlen(str), str);
}

void	shoot(Rocket *iam)
{
	int i;

	while (iam->is_running)
	{
		if (iam->is_shoot && iam->is_pause)
		{
			iam->is_shoot = 0;
			i = iam->GetRow() - 6;
			int col = iam->GetCol() + 6;
			while (i >= 0)
			{
				for (int j = 0; j < 50; j++)
				{
					if ((iam->enemyes[j].row <= i && iam->enemyes[j].row + 3 >= i) && (iam->enemyes[j].col <= col && col <= iam->enemyes[j].col + 9))
					{
						iam->enemyes[j].Destroy(iam->holst);
						iam->enemyes[j].row = -10;
						iam->enemyes[j].col = -10;
						iam->kill++;
						i = 0;
					}
				}
				mmvwprintw(iam->holst, i, col, "*");
				mmvwprintw(iam->holst, i + 1, col, " ");
				i -= 1;
				napms(12);
			}
			mmvwprintw(iam->holst, 0, col, " ");
		}
	}
}

void	enemy_move(Rocket *iam)
{
	while (iam->is_running )
	{
		if (iam->is_pause)
		{
			for (int i = 0; i < 50; i++)
			{
				if (iam->enemyes[i].row == iam->row) {
					iam->enemyes[i].row = -10;
					iam->enemyes[i].col = -10;
				}
				if (iam->enemyes[i].col != -10) {
					iam->enemyes[i].row++;
					mmvwprintw(iam->holst, iam->enemyes[i].row - 1, iam->enemyes[i].col, "           ");
					iam->enemyes[i].Print(iam->holst);
				}
				if ((iam->enemyes[i].row + 4 <= iam->GetRow() && iam->enemyes[i].row + 4 >= iam->GetRow() - 5) &&
					(iam->enemyes[i].col >= iam->GetCol() - 6 && iam->enemyes[i].col <= iam->GetCol() + 9)) {
					iam->is_pause = 0;
					iam->Destroy();
					iam->kill = 0;
					break ;
				}
			}
			if (iam->kill < 40)
				napms(60 - iam->kill);
			else
				napms(20);
		}
	}
}

void	enemy_spawn(Rocket *iam)
{
	while (iam->is_running)
	{
		if (iam->is_pause)
		{
			for (int i = 0; i < 50; i++) {
				if (iam->enemyes[i].col == -10) {
					iam->enemyes[i].row = 0;
					iam->enemyes[i].col = rand() % (iam->col - 9);
					break;
				}
			}
			if (iam->kill % 6 == 0 && iam->kill > 6)
				napms(10);
			else if (iam->kill <= 40)
				napms(1500 - iam->kill * 30);
			else
				napms(200);
		}
	}
}

void	refresh_pic(Rocket *iam)
{
	while (iam->is_running)
	{
		if (iam->is_pause)
		{
			iam->mutex.lock();
			attron(COLOR_PAIR(4));
			for (int i = 0; i < 130; i++) {
				mvwprintw(stdscr, i, 0, iam->holst[i + 10].c_str() + 20);
			}
			attron(COLOR_PAIR(1));
			mvwprintw(stdscr, iam->GetRow() - 5, iam->GetCol() + 5, "/");
			attron(COLOR_PAIR(2));
			mvwprintw(stdscr, iam->GetRow() - 5, iam->GetCol() + 6, "*");
			attron(COLOR_PAIR(1));
			mvwprintw(stdscr, iam->GetRow() - 5, iam->GetCol() + 7, "\\ ");
			mvwprintw(stdscr, iam->GetRow() - 4, iam->GetCol() + 4, "| S.| ");
			mvwprintw(stdscr, iam->GetRow() - 3, iam->GetCol() + 4, "| B.| ");
			mvwprintw(stdscr, iam->GetRow() - 2, iam->GetCol() + 3, "/| D.|\\ ");
			mvwprintw(stdscr, iam->GetRow() - 1, iam->GetCol() + 2, "/_| K.|_\\ ");
			attron(COLOR_PAIR(5));
			if (iam->kill > iam->best)
				iam->best = iam->kill;
			std::string str = std::to_string(iam->kill);
			mvwprintw(stdscr, 4, 5, "Kils: ");
			mvwprintw(stdscr, 4, 11, str.c_str());
			attron(COLOR_PAIR(6));
			mvwprintw(stdscr, 3, 5, "Best: ");
			str = std::to_string(iam->best);
			mvwprintw(stdscr, 3, 11, str.c_str());
			attron(COLOR_PAIR(2));
			mvwprintw(stdscr, 3, iam->col - 20, "Arrows for move");
			mvwprintw(stdscr, 4, iam->col - 20, "SPACE for shoot");
			mvwprintw(stdscr, 5, iam->col - 20, "ESC for exit");
			refresh();
			iam->mutex.unlock();
			napms(10);
		}
	}
}

int	main(void)
{
	int row, col;
	initscr();
	srand(time(NULL));
	start_color();
	getmaxyx(stdscr, row, col);
	int r = row;
	curs_set(0);
	keypad(stdscr, true);
	halfdelay(1);
	noecho();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	Rocket *iam = new Rocket();
	iam->row = row;
	iam->col = col;
	iam->best = 0;
	iam->is_running = 1;
	iam->is_shoot = 0;
	iam->is_pause = 1;
	iam->cul = col / 2 - 4;
	iam->ruw = row;
	iam->SetPosition(iam->ruw, iam->cul);
	std::thread enem_spawn(enemy_spawn, iam);
	std::thread enem_move(enemy_move, iam);
	std::thread enem_shoot(shoot, iam);
	std::thread ref(refresh_pic, iam);
	clear();
	while (iam->is_running)
	{
		if (iam->is_pause)
		{
			iam->SetPosition(iam->ruw, iam->cul);
			iam->Print();
			iam->mutex.lock();
			switch (wgetch(stdscr)) {
				case 27:
					iam->is_running = 0;
					break;
				case KEY_LEFT: {
					if (iam->cul - 3 >= 0)
						iam->cul -= 3;
					break;
				}
				case KEY_UP: {
					if (iam->ruw - 8 >= 0)
						iam->ruw -= 1;
					break;
				}
				case KEY_DOWN: {
					if (iam->ruw + 1 <= r)
						iam->ruw += 1;
					break;
				}
				case KEY_RIGHT: {
					if (iam->cul + 3 + 11 <= col)
						iam->cul += 3;
					break;
				}
				case 32: {
					iam->is_shoot = 1;
					break;
				}
			}
			iam->mutex.unlock();
		}
	}
	iam->mutex.unlock();
	delete (iam);
	//iam->mutex.unlock();
	enem_spawn.join();
	enem_move.join();
	enem_shoot.join();
	ref.join();
	endwin();
	return (0);
}
