/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gkrellm.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <dborysen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:20:11 by dborysen          #+#    #+#             */
/*   Updated: 2019/04/11 16:56:12 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_HPP
#define GKRELLM_HPP

#include <iostream>
#include <algorithm>
#include <ncurses.h>
#include <sys/utsname.h>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Gkrellm : public IMonitorDisplay, public IMonitorModule
{
public:	
	Gkrellm();
	~Gkrellm();

	void Start();

private:
	void	_StartNcursesMode();
	void	_EndNcursesMode() const;

	void	_MakeBox();

	void	OutputDolphin(WINDOW* win, int i) const;
	void	OutputTime(WINDOW* win) const;
	void	OutputOSIinfo(WINDOW* win) const;
	void	OutputUsernameAndHostname(WINDOW* win) const;
	void	OutputCPUAndRAM(WINDOW* win) const;
	void	OutputNetworkThroughput(WINDOW* win) const;
	void	OutputDisks(WINDOW* win) const;
	void	OutputProcessesNo(WINDOW* win) const;


	Gkrellm(const Gkrellm& other);
	Gkrellm& operator=(const Gkrellm& other);
};

#endif