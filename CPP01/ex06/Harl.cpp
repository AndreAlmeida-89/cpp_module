/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:09:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/17 20:13:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

Harl::Level Harl::_getLevelType(std::string &level)
{
	const std::string levels[NUMBER_OF_LEVELS] = {"DEBUG",
												  "INFO",
												  "WARNING",
												  "ERROR"};
	size_t i = 0;
	while (i < NUMBER_OF_LEVELS && levels[i] != level)
		i++;
	return ((Level)(i));
}

void Harl::complain(std::string level)
{
	switch (_getLevelType(level))
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl;

	case INFO:
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl;

	case WARNING:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl;

	case ERROR:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
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
