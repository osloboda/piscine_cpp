/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:18:24 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:18:25 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <Brain.hpp>
#include <string>

class Human
{
	public:
		Human();
		~Human();
		Brain getBrain(void);
		std::string identify(void);
	private:
	Brain _brain;
};

#endif
