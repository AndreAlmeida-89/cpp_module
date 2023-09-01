/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:44:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 22:53:29 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(
	std::string	&first_name,
	std::string	&last_name,
	std::string	&nickname,
	std::string	&phone_number,
	std::string	&darkest_secret
	) :
	_first_name(first_name),
	_last_name(last_name),
	_nickname(nickname),
	_phone_number(phone_number),
	_darkest_secret(darkest_secret) {}

Contact::Contact(){}

std::string	Contact::get_first_name() const
{
	return (_first_name);
}

std::string	Contact::get_last_name() const
{
	return (_last_name);
}

std::string	Contact::get_nickname() const
{
	return (_nickname);
}

void Contact::printContactInfo() const
{
	std::cout
	<< "First name: " << _first_name << std::endl
	<< "Last name: " <<  _last_name << std::endl
	<< "Nickname: " << _nickname << std::endl
	<< "Phone number: " << _phone_number << std::endl
	<< "Darkest secret: " << _darkest_secret << std::endl;
}