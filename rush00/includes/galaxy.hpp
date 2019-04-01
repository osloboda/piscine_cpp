/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:38:31 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 17:38:45 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GALAXY_HPP
# define GALAXY_HPP

#include "Rocket.hpp"
#include "Enemy.hpp"
# define RED(string) "\x1b[31m" string "\x1b[0m"
# define BRED(string) "\x1b[1;31m" string "\x1b[0m"
# define GREEN(string) "\x1b[0;32m" string "\x1b[0m"
# define BGREEN(string) "\x1b[1;32m" string "\x1b[0m"
# define YELLOW(string) "\x1b[0;33m" string "\x1b[0m"
# define BYELLOW(string) "\x1b[01;33m" string "\x1b[0m"
# define BLUE(string) "\x1b[0;34m" string "\x1b[0m"
# define BBLUE(string) "\x1b[1;34m" string "\x1b[0m"
# define MAGENTA(string) "\x1b[0;35m" string "\x1b[0m"
# define BMAGENTA(string) "\x1b[1;35m" string "\x1b[0m"
# define CYAN(string) "\x1b[0;36m" string "\x1b[0m"
# define BCYAN(string) "\x1b[1;36m" string "\x1b[0m"

#include <mutex>

void	mmvwprintw(std::string holst[130], int row, int col, const char *str);

#endif
