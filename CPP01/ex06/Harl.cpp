/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:09:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/17 19:47:19 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl() {}

Level Harl::_getLevelType(std::string &level)
{
	size_t i = 0;
	while (i < NUMBER_OF_LEVELS && _levels[i] != level)
		i++;
	return ((Level)(i));
}

void Harl::complain(std::string level)
{
	switch (_getLevelType(level))
	{
	case DEBUG:
		std::cout << "[ " << _levels[DEBUG] << " ]" << std::endl;
		debug();
		std::cout << std::endl;

	case INFO:
		std::cout << "[ " << _levels[INFO] << " ]" << std::endl;
		info();
		std::cout << std::endl;

	case WARNING:
		std::cout << "[ " << _levels[WARNING] << " ]" << std::endl;
		warning();
		std::cout << std::endl;

	case ERROR:
		std::cout << "[ " << _levels[ERROR] << " ]" << std::endl;
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

const std::string Harl::_levels[NUMBER_OF_LEVELS] = {"DEBUG",
													 "INFO",
													 "WARNING",
													 "ERROR"};
