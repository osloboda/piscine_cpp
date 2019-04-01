/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:11:54 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/27 22:13:39 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string	brain = "HI THIS IS BRAIN";
    std::string	*pointer = &brain;
    std::string	&reference = brain;
    std::cout  << brain << std::endl;
    std::cout << *pointer << std::endl;
    std::cout  << reference << std::endl;
    return (0);
}
