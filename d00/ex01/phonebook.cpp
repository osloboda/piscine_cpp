/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:37:11 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/26 15:37:15 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

phonebook::phonebook(void)
{
	this->contactnum = 0;
}

contact::contact(void)
{
	this->contact_id = 0;
	this->birthdaydate = "";
	this->darkestsecret = "";
	this->emailadress = "";
	this->favoritemeal = "";
	this->firstname = "";
	this->lastname = "";
	this->login = "";
	this->nickname = "";
	this->phonenumber = "";
	this->postaladress = "";
	this->underwear = "";
}

bool phonebook:: add(contact &cont)
{
    this->contacts[this->contactnum++] = cont;
    return (1);
}

contact &phonebook:: search(int id, phonebook &book)
{
	for (int i = 0; i < 8; i++)
	{
		if (book.contacts[i].contact_id == id)
			return (book.contacts[i]);
	}
	return (*book.contacts);
}

