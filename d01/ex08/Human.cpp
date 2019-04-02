/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:10 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:54:10 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "intimidatingShout " << target << std::endl;
}

void Human::meleeAttack(std::string const &target)
{
	std::cout << "meleeAttack " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "rangedAttack " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	void (Human::*actions[3])(std::string const &t) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string a_names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	for (int i = 0; i < 3; i++)
	{
		if (a_names[i] == action_name)
			(this->*actions[i])(target);
	}
}