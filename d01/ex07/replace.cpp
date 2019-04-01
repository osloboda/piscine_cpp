/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:48:31 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 18:49:19 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string get_file_name(std::string str)
{
	int i = 0;
	std::string str2;
	str2 = str;
	while(str2[i]) {
		str2[i] = toupper(str2[i]);
		i++;
	}
	str2.append(".replace");
	return (str2);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Usage ./replace FILENAME s1 s2\n";
	else
	{
		std::ifstream fin(argv[1]);
		std::ofstream find(get_file_name(argv[1]));
		std::string str;
		size_t k = 0;
		if (!fin)
		{
			std::cout << "Can't read " << argv[1] << std::endl;
			return (0);
		}
		if (!*(argv[2]) || !*(argv[3]))
		{
			std::cout << "Some string is emplty(" << std::endl;
			return (0);
		}
		getline (fin, str, '\0');
		while (std::string::npos != (k = str.find(argv[2], k)))
		{
			str.replace(k, strlen(argv[2]), argv[3]);
			k += strlen(argv[2]);
		}
		find << str;
		std::cout << "Writing to the output " << get_file_name(argv[1]) << "\n";
	}
	return (0);
}
