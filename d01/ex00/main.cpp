/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:39:23 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 17:59:06 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ponny.hpp"

static void ponyOnTheHeap(void)
{
    Ponny    *Maxim = new(class Ponny);

	Maxim->ponny_creat("Maxim");
	Maxim->ponny_colour("Pink");
	Maxim->ponny_kill("Maxim");
	delete(Maxim);
}

static void ponyOnTheStack(void)
{
    Ponny    Anjela;

    Anjela.ponny_creat("Anjela");
    Anjela.ponny_colour("Grey");
	Anjela.ponny_kill("Anjela");
}


int	main(void)
{
 	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
