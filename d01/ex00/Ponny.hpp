/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ponny.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:36:46 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 16:52:58 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONNY_HPP
# define PONNY_HPP

#include <string>

class	Ponny
{
	public:
		std::string name;
		std::string colour;
		void ponny_creat(std::string name);
		void ponny_kill(std::string name);
		void ponny_colour(std::string colour);
};

#endif
