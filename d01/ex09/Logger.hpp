/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:26:22 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/02 16:28:40 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>

class Logger
{
	public:
		Logger(std::string file);
		void	log(std::string const &dest, std::string const &message);
	private:
		std::string	file;
		int		index;
		void	logToConsole(std::string log);
		void	logToFile(std::string log);
		std::string	makeLogEntry(std::string log);
};

#endif
