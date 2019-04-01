/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:56:06 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 16:58:19 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak(void)
{
    std::string*	panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;
    delete panthere;
}
