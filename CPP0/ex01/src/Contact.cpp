/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:44:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 22:18:11 by andde-so         ###   ########.fr       */
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

Contact::Contact(int index)
{
	_index = index;
	std::cout << "First name: ";
	std::getline(std::cin, _first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, _last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, _nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, _phone_number);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, _darkest_secret);
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

void	Contact::printLine() const
{
	std::cout << "|"
	<< ft_resize(std::to_string(_index)) << "|"
	<< ft_resize(_first_name) << "|"
	<< ft_resize(_last_name) << "|"
	<< ft_resize(_nickname) << "|"
	<< std::endl;
}