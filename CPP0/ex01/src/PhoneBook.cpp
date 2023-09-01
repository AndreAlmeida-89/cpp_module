/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:52:52 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 22:20:08 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


void PhoneBook::add()
{
	size_t	i;

	if (_size < _capacity)
	{
		_contacts[_size] = Contact(_size);
		_size++;
	}
	else
	{
		for (i = 0; i < _capacity - 1; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[i] = Contact(i);
	}
}

void PhoneBook::search() const
{
	int			index;
	std::string index_input;

	if (_size == 0)
		return ;
	print_table();
	std::cout << "Choose contact index: ";
	std::getline(std::cin, index_input);
	index = std::stoi(index_input);
	if (index < 0 || index >= (int)_size)
		return ;
	_contacts[index].printContactInfo();
}

void PhoneBook::print_table() const
{
	const size_t	width = 45;

	std::cout << std::string(width, '-') << std::endl;
	std::cout << "|"
	<< ft_resize("INDEX") << "|"
	<< ft_resize("FIRST NAME") << "|"
	<< ft_resize("LAST NAME") << "|"
	<< ft_resize("NICK NAME") << "|"
	<< std::endl;
	std::cout << std::string(width, '-') << std::endl;
	for (size_t i = 0; i < _size; i++)
		_contacts[i].printLine();
	std::cout << std::string(width, '-') << std::endl;
}