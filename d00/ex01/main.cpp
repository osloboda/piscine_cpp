/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:15:27 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/31 17:56:42 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <string>
# include <iomanip>

void	print_search(phonebook &book)
{
	std::cout << "        id|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << book.contacts[i].contact_id << std::setfill(' ') << "|";
		std::string firstname = book.contacts[i].firstname;
		if (firstname.size() > 10)
			firstname = firstname.substr(0, 9) + ".";
		std::cout << std::setw(10) << firstname << std::setfill(' ') << "|";
		std::string lastname = book.contacts[i].lastname;
		if (lastname.size() > 10)
			lastname = lastname.substr(0, 9) + ".";
		std::cout << std::setw(10) << lastname << std::setfill(' ') << "|";
		std::string nickname = book.contacts[i].nickname;
		if (nickname.size() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << std::setfill(' ') << "|";
		std::cout << std::endl;
	}
}

void	search_by_id(phonebook &book)
{
	if (book.contactnum == 0)
	{
		std::cout << "Phonebook if empty!" << std::endl;
		return;
	}
	print_search(book);
	std::string id;
	std::cout << "Enter id: " << std::endl;
	std::getline(std::cin, id);
	contact cont;
	if (std::stoi(id) > 8 || std::stoi(id) < 1)
	{
		std::cout << "No such contact!" << std::endl;
		return;
	}
	cont = book.search(std::stoi(id), book);
	std::cout << "First name: " << cont.firstname << std::endl;
	std::cout << "Last name: " << cont.lastname << std::endl;
	std::cout << "Nickname: " << cont.nickname << std::endl;
	std::cout << "Login: " << cont.login << std::endl;
	std::cout << "Postal address: " << cont.postaladress << std::endl;
	std::cout << "Email address: " << cont.emailadress << std::endl;
	std::cout << "Phone number: " << cont.phonenumber << std::endl;
	std::cout << "Birthday date: " << cont.birthdaydate << std::endl;
	std::cout << "Favorite meal: " << cont.favoritemeal << std::endl;
	std::cout << "Underwear color: " << cont.underwear << std::endl;
	std::cout << "Darkest secret: " << cont.darkestsecret << std::endl;
}

void add_contact(phonebook &book)
{
	contact contact;
	if (book.contactnum == 8) {
		std::cout << "Phonebook if full!" << std::endl;
		return ;
	}
	std::cout << "Enter contact data:" << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, contact.firstname);
	std::cout << "Last name: ";
	std::getline(std::cin, contact.lastname);
	std::cout << "Nickname: ";
	std::getline(std::cin, contact.nickname);
	std::cout << "Login: ";
	std::getline(std::cin, contact.login);
	std::cout << "Postal address: ";
	std::getline(std::cin, contact.postaladress);
	std::cout << "Email address: ";
	std::getline(std::cin, contact.emailadress);
	std::cout << "Phone number: ";
	std::getline(std::cin, contact.phonenumber);
	std::cout << "Birthday date: ";
	std::getline(std::cin, contact.birthdaydate);
	std::cout << "Favorite meal: ";
	std::getline(std::cin, contact.favoritemeal);
	std::cout << "Underwear color: ";
	std::getline(std::cin, contact.underwear);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, contact.darkestsecret);
	std::cout << "Done!" << std::endl;
	contact.contact_id = book.contactnum + 1;
	book.add(contact);
}

int main(void)
{
	phonebook book = phonebook();
	std::string command;

	std::cout << "Phonebook is opened!" << std::endl;
	while (command != "EXIT")
	{
		std::cout << std::endl << "Type ADD, SEARCH or EXIT." << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof()==1)
			return (0);
		if (command == "ADD")
			add_contact(book);
		else if (command == "EXIT")
			std::cout << "I'll miss" << std::endl;
		else if (command == "SEARCH")
			search_by_id(book);
		else
			std::cout << "I don't understand you(" << std::endl;
	}
	return (0);
}
