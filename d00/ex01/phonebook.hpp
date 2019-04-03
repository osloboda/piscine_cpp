/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:22:56 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 17:54:15 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class		phonebook
{
	public:
		contact contacts[8];
		int contactnum;
		phonebook(void);
		bool add(contact &cont);
		contact &search(int id, phonebook &book);
};

#endif
