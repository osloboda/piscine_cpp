/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osloboda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:15:53 by osloboda          #+#    #+#             */
/*   Updated: 2019/03/26 15:22:40 by osloboda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	contact
{
	public:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string login;
	std::string postaladress;
	std::string emailadress;
	std::string phonenumber;
	std::string birthdaydate;
	std::string favoritemeal;
	std::string underwear;
	std::string darkestsecret;
	contact(void);
	int contact_id;
};

#endif
