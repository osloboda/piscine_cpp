/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:53:34 by osloboda          #+#    #+#             */
/*   Updated: 2019/04/04 17:53:36 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main() {
    Sorcerer robert(``Robert'', ``the Magnificent'');
    Victim jim(``Jimmy'');
    Peon joe(``Joe'');
    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);
    return 0; }