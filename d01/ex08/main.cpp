/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:57 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 18:48:47 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void)
{
	Human Bella;

	Bella.action("meleeAttack", "herself");
	Bella.action("intimidatingShout", "herself");
	Bella.action("rangedAttack", "herself");
	return (0);
}
