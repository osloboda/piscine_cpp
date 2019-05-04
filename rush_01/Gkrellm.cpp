/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gkrellm.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <dborysen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:29:23 by dborysen          #+#    #+#             */
/*   Updated: 2019/04/14 15:44:03 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gkrellm.hpp"
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <vector>

Gkrellm::Gkrellm() {}

Gkrellm::~Gkrellm() {}

Gkrellm::Gkrellm(const Gkrellm& other)
{
	*this = other;
}

Gkrellm& Gkrellm::operator=(const Gkrellm& other)
{
	static_cast<void>(other);
	return *this;
}

static std::string GetOsName()
{
    #ifdef _WIN32
    	return "Windows 32-bit";
    #elif _WIN64
    	return "Windows 64-bit";
    #elif __unix || __unix__
    	return "Unix";
    #elif __APPLE__ || __MACH__
    	return "Mac OSX";
    #elif __linux__
    	return "Linux";
    #elif __FreeBSD__
    	return "FreeBSD";
    #else
    	return "Other";
    #endif
}  

void Gkrellm::OutputDolphin(WINDOW* win, int i) const
{
	wattron(win, COLOR_PAIR(1));
	if (!(i % 2))
	{
		mvwprintw(win, 28, 1, "             ,-._");
		mvwprintw(win, 29, 1, "           _.-'  '--.");
		mvwprintw(win, 30, 1, "         .'      _  -`\\_");
		mvwprintw(win, 31, 1, "        / .----.`_.'----'");
		mvwprintw(win, 32, 1, "        ;/     `");
		mvwprintw(win, 33, 1, "      /_;");
		mvwprintw(win, 34, 1, " ");
		mvwprintw(win, 35, 1, "      ._      ._      ._      ._ ");
		mvwprintw(win, 36, 1, "  _.-._)`\\_.-._)`\\_.-._)`\\_.-._)`\\_.-._");
	}
	else
	{
		mvwprintw(win, 28, 1, "                 ");
		mvwprintw(win, 29, 1, "                      ");
		mvwprintw(win, 30, 1, "                         ");
		mvwprintw(win, 31, 1, "                          ");
		mvwprintw(win, 32, 1, "                  ");
		mvwprintw(win, 33, 1, "         ");
		mvwprintw(win, 34, 1, " ");
		mvwprintw(win, 35, 1, "      ._      ._      ._      ._ ");
		mvwprintw(win, 36, 1, "  _.-._)`\\_.-._)`\\_.-._)`\\_.-._)`\\_.-._");
	}
	wattroff(win, COLOR_PAIR(1));
}

void Gkrellm::OutputUsernameAndHostname(WINDOW* win) const
{
	char userName[10];
	char hostname[15];

	getlogin_r(userName, 10);
	gethostname(hostname, 15);
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 1, 1, ("Username:	" + std::string(userName)).c_str());
	mvwprintw(win, 2, 1, ("Hostname:	" + std::string(hostname)).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 3, 1,
		(std::string("-----------------------------------------")).c_str());
}

void Gkrellm::OutputOSIinfo(WINDOW* win) const
{
	utsname osInfo;

	if(uname(&osInfo))
		exit(-1);
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 4, 1, ("OS info:	" + GetOsName()).c_str());
	mvwprintw(win, 5, 1, ("OS release:	" + std::string(osInfo.release)).c_str());
	mvwprintw(win, 6, 1, ("OS sysname:	" + std::string(osInfo.sysname)).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 7, 1,
		(std::string("-----------------------------------------")).c_str());
}

void	Gkrellm::OutputTime(WINDOW* win) const
{
	std::chrono::time_point<std::chrono::system_clock> end =
		std::chrono::system_clock::now();

   	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 8, 1, ("Date / Time:	" + std::string(std::ctime(&end_time))).erase(37).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 9, 1,
		(std::string("-----------------------------------------")).c_str());
	
}

void	Gkrellm::OutputCPUAndRAM(WINDOW* win) const
{
	std::system("top -l 1 | grep -E \"^CPU|^Phys\" > buff");
	std::ifstream				ifs("buff");
	std::vector<std::string>	cpu;
	std::string					buff;

	while(getline(ifs, buff, ' '))
		cpu.push_back(buff);

	ifs.close();
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 10, 1, ("CPU user:	" + cpu.at(2)).c_str());
	mvwprintw(win, 11, 1, ("CPU system:	" + cpu.at(4)).c_str());
	mvwprintw(win, 12, 1, ("CPU idle:	" + cpu.at(6)).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 13, 1,
		(std::string("-----------------------------------------")).c_str());

	std::string usedRamStr = cpu.at(11);

	usedRamStr.erase(std::remove(usedRamStr.begin(), usedRamStr.end(), '('),
		usedRamStr.end());
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 14, 1, ("RAM:		" + cpu.at(9)).c_str());
	mvwprintw(win, 15, 1, ("RAM used:	" + usedRamStr).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 16, 1,
		(std::string("-----------------------------------------")).c_str());
}

void	Gkrellm::OutputNetworkThroughput(WINDOW* win) const
{
	std::system("top -l 1 -n0 | grep -E \"^Net\" > Net_buff");
	std::ifstream				ifs("Net_buff");
	std::vector<std::string>	cpu;
	std::string					buff;

	while(getline(ifs, buff, ' '))
		cpu.push_back(buff);

	ifs.close();
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 17, 1, ("Networks in:	" + cpu.at(2)).c_str());
	mvwprintw(win, 18, 1, ("Networks out:	" + cpu.at(4)).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 19, 1,
		(std::string("-----------------------------------------")).c_str());
}

void	Gkrellm::OutputDisks(WINDOW* win) const
{
	std::system("top -l 1 | head | grep -E \"Disks\" > Disks_buff");
	std::ifstream				ifs("Disks_buff");
	std::vector<std::string>	cpu;
	std::string					buff;

	while(getline(ifs, buff, ' '))
		cpu.push_back(buff);

	ifs.close();
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 20, 1, ("Disks read:	" + cpu.at(1)).c_str());
	mvwprintw(win, 21, 1, ("Disks written:	" + cpu.at(3)).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 22, 1,
		(std::string("-----------------------------------------")).c_str());
}

void	Gkrellm::OutputProcessesNo(WINDOW* win) const
{
	std::system("top -l 1 | head | grep -E \"Processes:\" > Processes_buff");
	std::ifstream				ifs("Processes_buff");
	std::vector<std::string>	cpu;
	std::string					buff;

	while(getline(ifs, buff, ' '))
		cpu.push_back(buff);

	ifs.close();
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 23, 1, ("Processes total:	" + cpu.at(1)).c_str());
	mvwprintw(win, 24, 1, ("Processes running:	" + cpu.at(3)).c_str());
	mvwprintw(win, 25, 1, ("Processes sleeping:	" + cpu.at(5)).c_str());
	mvwprintw(win, 26, 1, ("Processes threads:	" + cpu.at(7)).c_str());
	wattroff(win, COLOR_PAIR(2));
	mvwprintw(win, 27, 1,
		(std::string("-----------------------------------------")).c_str());
}

void	Gkrellm::Start()
{
	_StartNcursesMode();

	OutputUsernameAndHostname(_infoBox);
	OutputOSIinfo(_infoBox);
	int i = 0;
	while (wgetch(_infoBox) != 'q')
	{
		OutputTime(_infoBox);
		OutputCPUAndRAM(_infoBox);
		OutputNetworkThroughput(_infoBox);
		OutputDisks(_infoBox);
		OutputProcessesNo(_infoBox);
		OutputDolphin(_infoBox, i++);
		wrefresh(_infoBox);
	}

	_EndNcursesMode();
}

void	Gkrellm::_StartNcursesMode()
{
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	noecho();
	raw();
	curs_set(0);
	timeout(0);
	_MakeBox();
}

void	Gkrellm::_MakeBox()
{
	int heigh = 38;
	int width = 43;
	int startY = 0;
	int startX = 0;

	_infoBox = newwin(heigh, width, startY, startX);

	refresh();
	box(_infoBox, 0, 0);
	wrefresh(_infoBox);
	nodelay(_infoBox, true);
	keypad(_infoBox, TRUE);
}

void	Gkrellm::_EndNcursesMode() const
{
	getch();
	endwin();
}
