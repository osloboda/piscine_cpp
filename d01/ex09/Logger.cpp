/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:28:49 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/02 16:29:03 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <iostream>
#include <string>
#include <fstream>

Logger::Logger(std::string file)
{
	this->file = file;
	this->index = 0;
}

std::string Logger::makeLogEntry(std::string log)
{
	long int ltime;
	time(&ltime);
	char *times = ctime (&ltime);
	return (times + std::to_string(this->index) + " " + log);
}

void Logger::logToConsole(std::string log)
{
	std::cout << this->makeLogEntry(log) << std::endl;
}

void Logger::logToFile(std::string log)
{
	std::ofstream file(this->file);
	file << this->makeLogEntry(log) << std::endl;
}

void Logger::log(std::string const &dest, std::string const &message)
{
	void (Logger::*log_ways[2])( std::string log ) = {&Logger::logToConsole, &Logger::logToFile};

	std::string	log_way_names[2] = {"Console", "File"};
	for (int i = 0; i < 2; i++)
	{
		if (log_way_names[i] == dest)
		{
			(this->*log_ways[i])(message);
			break ;
		}
	}
	this->index++;
}