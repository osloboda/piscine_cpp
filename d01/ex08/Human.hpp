/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:22 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:54:06 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>

class Human
{
	private:
		void meleeAttack(std::string const & target);
		void rangedAttack(std::string const & target);
		void intimidatingShout(std::string const & target);
	public:
		void action(std::string const & action_name, std::string const & target);
};

#endif