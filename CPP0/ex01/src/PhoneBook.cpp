/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:52:52 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/01 20:38:48 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string>

void	PhoneBook::_display_phone_book() const
{
	const size_t width = 45;

	std::cout << std::string(width, '-') << std::endl;
	std::cout << "|"
			  << ft_set_width("INDEX") << "|"
			  << ft_set_width("FIRST NAME") << "|"
			  << ft_set_width("LAST NAME") << "|"
			  << ft_set_width("NICK NAME") << "|"
			  << std::endl;
	std::cout << std::string(width, '-') << std::endl;
	for (size_t i = 0; i < _size; i++)
		_print_line(_contacts[i], i);
	std::cout << std::string(width, '-') << std::endl;
}

void	PhoneBook::_print_line(Contact contact, size_t index) const
{
	char	c;
	
	c = index + '0';
	std::cout << "|"
	<< ft_set_width(&c) << "|"
	<< ft_set_width(contact.get_first_name()) << "|"
	<< ft_set_width(contact.get_last_name()) << "|"
	<< ft_set_width(contact.get_nickname()) << "|"
	<< std::endl;
}

void	PhoneBook::add()
{
	size_t	i;
	Contact	contact;

	if (!contact.create_contact())
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
	{
		std::cout << "(!) Phone book is empty." << std::endl;
		return ;
	}
	_display_phone_book();
	std::cout << "Choose contact index: ";
	std::getline(std::cin, index_input);
	if (!ft_stoi(index_input, &index) ||
		index < 0 || index >= (int)_size)
	{
		std::cout << "(!) Ivalid index." << std::endl;
		return ;
	}
	_contacts[index].printContactInfo();
}