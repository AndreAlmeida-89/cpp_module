/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:42:08 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/30 23:59:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	std::string	command;
	PhoneBook	phonebook = PhoneBook();

	while (command != "EXIT")
	{
		std::cout << "Command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}