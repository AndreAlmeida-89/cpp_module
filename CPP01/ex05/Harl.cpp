/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:09:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 15:14:00 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
	const size_t nbOfLevels = 4;
	const std::string levels[nbOfLevels] = {"DEBUG",
											"INFO",
											"WARNING",
											"ERROR"};
	void (Harl::*arr[nbOfLevels])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	for (size_t i = 0; i < nbOfLevels; i++)
		if (level == levels[i])
			(this->*arr[i])();
}

void Harl::debug(void)
{
	std::cout << "This is a debug message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "This is an info message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is a warning message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is an error message" << std::endl;
}
