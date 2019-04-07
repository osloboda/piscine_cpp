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
#include <chrono>
#include <cstring>
#include <ncurses.h>
#include <string>
#include "../includes/Enemy.hpp"


void	mmvwprintw(std::string holst[130], int row, int col, const char *str)
{
	holst[row + 10].replace(col + 20 , strlen(str), str);
}

void	shoot(Rocket *iam)
{
	if (iam->is_pause)
	{
	    for (int i = 0; i < 10; i++)
        {
	    	if (iam->bullets[i].row != -10)
			{
                iam->bullets[i].row -= 2;
				mmvwprintw(iam->holst, iam->bullets[i].row, iam->bullets[i].col, "*");
				mmvwprintw(iam->holst, iam->bullets[i].row + 2, iam->bullets[i].col, " ");
	        	for (int j = 0; j < 100; j++)
	        	{
	            	if ((iam->enemyes[j].row <= iam->bullets[i].row && iam->enemyes[j].row + 3 >= iam->bullets[i].row) && (iam->enemyes[j].col <= iam->bullets[i].col && iam->bullets[i].col <= iam->enemyes[j].col + 9))
	            	{
	                	iam->enemyes[j].Destroy(iam->holst);
	                	iam->enemyes[j].row = -10;
	                	iam->enemyes[j].col = -10;
	                	iam->bullets[i].col = -10;
	                	iam->bullets[i].row = -10;
	                	iam->kill++;
						break;
					}
	    		}
	        	if (iam->bullets[i].row < 0)
                {
                    iam->bullets[i].col = -10;
                    iam->bullets[i].row = -10;
                }
			}
		}
	}
}

void	enemy_move(Rocket *iam)
{
	if (iam->is_pause)
	{
		for (int i = 0; i < 100; i++)
		{
			if (iam->enemyes[i].row == iam->row)
			{
				iam->enemyes[i].row = -10;
				iam->enemyes[i].col = -10;
			}
			if (iam->enemyes[i].bullet.row >= iam->row || iam->enemyes[i].bullet.row == -10)
			{
				iam->enemyes[i].bullet.row = iam->enemyes[i].row;
				iam->enemyes[i].bullet.col = iam->enemyes[i].col + 3;
			}
			if (iam->enemyes[i].col != -10)
			{
				iam->enemyes[i].bullet.row += 2		;
				mmvwprintw(iam->holst, iam->enemyes[i].bullet.row, iam->enemyes[i].bullet.col, "*");
				mmvwprintw(iam->holst, iam->enemyes[i].bullet.row - 2, iam->enemyes[i].bullet.col, " ");
				if ((iam->enemyes[i].bullet.row <= iam->GetRow() && iam->enemyes[i].bullet.row >= iam->GetRow() - 5) &&
					(iam->enemyes[i].bullet.col >= iam->GetCol() + 3 && iam->enemyes[i].bullet.col <= iam->GetCol() + 12	))
				{
					iam->is_pause = 0;
					iam->Destroy();
					iam->kill = 0;
					break ;
				}
				iam->enemyes[i].row++;
				mmvwprintw(iam->holst, iam->enemyes[i].row - 1, iam->enemyes[i].col, "           ");
				iam->enemyes[i].Print(iam->holst);
			}
			if ((iam->enemyes[i].row + 4 <= iam->GetRow() && iam->enemyes[i].row + 4 >= iam->GetRow() - 5) &&
			(iam->enemyes[i].col >= iam->GetCol() - 6 && iam->enemyes[i].col <= iam->GetCol() + 9))
			{
				iam->is_pause = 0;
				iam->Destroy();
				iam->kill = 0;
				break ;
			}
		}
	}
}

void	enemy_spawn(Rocket *iam)
{
	if (iam->is_pause)
	{
		for (int i = 0; i < 100; i++)
		{
			if (iam->enemyes[i].col == -10)
			{
				iam->enemyes[i].row = 0;
				iam->enemyes[i].col = rand() % (iam->col - 9);
				break;
			}
		}
	}
}

void print_moon(Rocket *iam)
{
	if (iam->moon > 70)
		iam->moon = 0;
	attron(COLOR_PAIR(3));
	switch (iam->moon)
	{
		case 0:
			mvwprintw(stdscr, 5, iam->col - 50, "   _....._");
			mvwprintw(stdscr, 6, iam->col - 50, " .:::::::::.");
			mvwprintw(stdscr, 7, iam->col - 50, ":::::::::::::");
			mvwprintw(stdscr, 8, iam->col - 50, ":::::::::::::");
			mvwprintw(stdscr, 9, iam->col - 50, "`:::::::::::'");
			mvwprintw(stdscr, 10, iam->col - 50, "  `':::::''");
			break;
		case 10:
			mvwprintw(stdscr, 5, iam->col - 50, "   __");
			mvwprintw(stdscr, 6, iam->col - 50, " .:::::.");
			mvwprintw(stdscr, 7, iam->col - 50, "::::::::.");
			mvwprintw(stdscr, 8, iam->col - 50, ":::::::::");
			mvwprintw(stdscr, 9, iam->col - 50, "`:::::::'");
			mvwprintw(stdscr, 10, iam->col - 50, "  `':::");
			break;
		case 20:
			mvwprintw(stdscr, 5, iam->col - 50, "   _..");
			mvwprintw(stdscr, 6, iam->col - 50, " .::::");
			mvwprintw(stdscr, 7, iam->col - 50, "::::::");
			mvwprintw(stdscr, 8, iam->col - 50, "::::::");
			mvwprintw(stdscr, 9, iam->col - 50, "`:::::");
			mvwprintw(stdscr, 10, iam->col - 50, " `'::.");
			break;
		case 30:
			mvwprintw(stdscr, 5, iam->col - 50, "   _..");
			mvwprintw(stdscr, 6, iam->col - 50, " .::'");
			mvwprintw(stdscr, 7, iam->col - 50, ":::");
			mvwprintw(stdscr, 8, iam->col - 50, ":::");
			mvwprintw(stdscr, 9, iam->col - 50, "`::.");
			mvwprintw(stdscr, 10, iam->col - 50, "  `':.");
			break;
		case 40:
			mvwprintw(stdscr, 5, iam->col - 50, "           ");
			mvwprintw(stdscr, 6, iam->col - 50, "           ");
			mvwprintw(stdscr, 7, iam->col - 50, "           ");
			mvwprintw(stdscr, 8, iam->col - 50, "           ");
			mvwprintw(stdscr, 9, iam->col - 50, "           ");
			mvwprintw(stdscr, 10, iam->col - 50, "          ");
			break;
		case 50:
			mvwprintw(stdscr, 5, iam->col - 50, "      ..._");
			mvwprintw(stdscr, 6, iam->col - 50, "        `::.");
			mvwprintw(stdscr, 7, iam->col - 50, "          :::");
			mvwprintw(stdscr, 8, iam->col - 50, "          :::");
			mvwprintw(stdscr, 9, iam->col - 50, "         .::'");
			mvwprintw(stdscr, 10, iam->col - 50, "      ..:''");
			break;
		case 60:
			mvwprintw(stdscr, 5, iam->col - 50, "      .._");
			mvwprintw(stdscr, 6, iam->col - 50, "      ::::.");
			mvwprintw(stdscr, 7, iam->col - 50, "      ::::::");
			mvwprintw(stdscr, 8, iam->col - 50, "      ::::::");
			mvwprintw(stdscr, 9, iam->col - 50, "      :::::'");
			mvwprintw(stdscr, 10, iam->col - 50, "      ::''");
			break;
		case 70:
			mvwprintw(stdscr, 5, iam->col - 50, "        _");
			mvwprintw(stdscr, 6, iam->col - 50, "     .::::.");
			mvwprintw(stdscr, 7, iam->col - 50, "    ::::::::");
			mvwprintw(stdscr, 8, iam->col - 50, "    ::::::::");
			mvwprintw(stdscr, 9, iam->col - 50, "    '::::::'");
			mvwprintw(stdscr, 10, iam->col - 50, "       ''");
			break;
	}
}

void	refresh_pic(Rocket *iam)
{
	if (iam->is_pause)
	{
		attron(COLOR_PAIR(4));
		for (int i = 0; i < 130; i++)
			mvwprintw(stdscr, i, 0, iam->holst[i + 10].c_str() + 20);
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
		print_moon(iam);
		refresh();
	}
}

int	main(void)
{
	int row, col;
	initscr();
	srand(time(NULL));
	start_color();
	cbreak();
	getmaxyx(stdscr, row, col);
	int r = row;
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, 1);
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
	iam->k = 20;
	iam->l = 0;
	iam->m = 0;
	int y = 0;
	iam->SetPosition(iam->ruw, iam->cul);
	clear();
	while (iam->is_running)
	{
		napms(30);
		if (iam->is_pause)
		{
		    if (iam->l == iam->k)
		    {
				iam->l = 0;
				if (iam->m == 3 && iam->k > 3)
				{
					iam->m = 0;
					iam->k -= 1;
				}
				iam->m++;
                enemy_spawn(iam);
            }
            iam->l++;
		    y++;
		    if (!(y % 10))
		    	iam->moon += 10;
            enemy_move(iam);
			shoot(iam);
			refresh_pic(iam);
			iam->SetPosition(iam->ruw, iam->cul);
			switch (wgetch(stdscr))
			{
				case 27:
					iam->is_running = 0;
					break;
				case KEY_LEFT:
					{
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
					case 32:
					{
						for (int i = 0; i < 10; i++)
							if (iam->bullets[i].col == -10)
							{
								iam->bullets[i].col = iam->GetCol() + 6;
								iam->bullets[i].row = iam->GetRow() - 6;
								break;
							}
						break;
					}
				}

		}
	}
	delete (iam);
	endwin();
	return (0);
}
