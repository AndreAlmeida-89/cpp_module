/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:44:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/01 20:37:53 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(){}

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

bool	Contact::_read_contact_info(const std::string &label, std::string &str)
{
	std::cout << ft_set_width(label, 14) << ": ";
	std::getline(std::cin, str);
	return (str.empty() == false);
}

bool	Contact::create_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	if (!_read_contact_info("First name", first_name) ||
		!_read_contact_info("Last name", last_name) ||
		!_read_contact_info("Nick name", nickname) ||
		!_read_contact_info("Phone number", phone_number) ||
		!_read_contact_info("Darkest secret", darkest_secret))
		{
			std::cout << "(!) Contact field can't be empty!" << std::endl;
			return (false);
		}
	*this = Contact(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret);
	return (true);
}

void Contact::printContactInfo() const
{
	const size_t	width = 16;

	std::cout
	<< ft_set_width("First name: ", width) << _first_name << std::endl
	<< ft_set_width("Last name: ", width) <<  _last_name << std::endl
	<< ft_set_width("Nickname: ", width) << _nickname << std::endl
	<< ft_set_width("Phone number: ", width) << _phone_number << std::endl
	<< ft_set_width("Darkest secret: ", width) << _darkest_secret << std::endl;
}