/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:44:57 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/26 15:02:13 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < argc)
		{
			while (*(argv[i]))
			{
				if (*(argv[i]) >= 'a' && *(argv[i]) <= 'z')
					std::cout << (char)(*(argv[i]) - ' ');
				else
					std::cout << (char)*(argv[i]);
				(argv[i])++;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
