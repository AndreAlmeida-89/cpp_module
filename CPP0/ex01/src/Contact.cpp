/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:44:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 00:38:35 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(){}

Contact::Contact(int index)
{
	_index = index;
	std::cout << "Firt name: ";
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