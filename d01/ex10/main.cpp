/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:47:16 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/03 17:04:53 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <fstream>
 
int main(int argc, char** argv)
{
    std::string str;
	if (argc < 2)
	{
		while (getline(std::cin, str))
			std::cout << str << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
    	std::ifstream ifs(argv[i], std::ifstream::in);
		if (ifs.is_open())
        	while (!ifs.eof())
			{
            	getline(ifs, str);
				std::cout << str;
				if (!ifs.eof())
        	    	std::cout << std::endl;
    	    }
		else
		   std::cout << "cato9tails: " << argv[i] << ": No such file or directory" << std::endl;
	}
	return (0);
}
