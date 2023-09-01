/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:52:52 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 23:18:41 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	PhoneBook::read_contact_info(const std::string &label, std::string &str)
{
	std::cout << label << ": ";
	std::getline(std::cin, str);
	return (str.empty() == false);
}

bool	PhoneBook::create_contact(Contact *contact)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	if (!read_contact_info("First name", first_name) ||
		!read_contact_info("Last name", last_name) ||
		!read_contact_info("Nick name", nickname) ||
		!read_contact_info("Phone number", phone_number) ||
		!read_contact_info("Darkest secret", darkest_secret))
		{
			std::cout << "Contact field can't be empty!" << std::endl;
			return (false);
		}
	*contact = Contact(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret);
	return (true);
}

void	PhoneBook::printTable() const
{
	const size_t width = 45;

	std::cout << std::string(width, '-') << std::endl;
	std::cout << "|"
			  << ft_resize("INDEX") << "|"
			  << ft_resize("FIRST NAME") << "|"
			  << ft_resize("LAST NAME") << "|"
			  << ft_resize("NICK NAME") << "|"
			  << std::endl;
	std::cout << std::string(width, '-') << std::endl;
	for (size_t i = 0; i < _size; i++)
		printLine(_contacts[i], i);
	std::cout << std::string(width, '-') << std::endl;
}

void	PhoneBook::printLine(Contact contact, size_t index) const
{
	std::cout << "|"
	<< ft_resize(std::to_string(index)) << "|"
	<< ft_resize(contact.get_first_name()) << "|"
	<< ft_resize(contact.get_last_name()) << "|"
	<< ft_resize(contact.get_nickname()) << "|"
	<< std::endl;
}

void	PhoneBook::add()
{
	size_t	i;

	Contact	contact;
	if (!create_contact(&contact))
		return ;
	if (_size < _capacity)
	{
		_contacts[_size] = contact;
		_size++;
	}
	else
	{
		for (i = 0; i < _capacity - 1; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[i] = contact;
	}
}

void	PhoneBook::search() const
{
	int index;
	std::string index_input;

	if (_size == 0)
		return;
	printTable();
	std::cout << "Choose contact index: ";
	std::getline(std::cin, index_input);
	index = std::stoi(index_input);
	if (index < 0 || index >= (int)_size)
		return;
	_contacts[index].printContactInfo();
}