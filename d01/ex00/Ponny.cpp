/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ponny.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:37:55 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 16:53:49 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ponny.hpp"
#include <string>
#include <iostream>

void Ponny:: ponny_creat(std::string name)
{
	this->name = name;
	std::cout << "Ponny " << name << " born!" << std::endl;
}

void Ponny:: ponny_colour(std::string colour)
{
	this->colour = colour;
	std::cout << "Now ponny " << name << " is " << colour << std::endl;
}

void Ponny:: ponny_kill(std::string name)
{
	this->name = "";
	std::cout << "Ponny " << name << " died!" << std::endl;
}
