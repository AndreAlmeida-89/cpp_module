/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:09:55 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 16:58:10 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->arr = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};
}

Harl::~Harl() {}

Level Harl::getLevel(std::string &level)
{
	size_t i = 0;
	while (i < NUMBER_OF_LEVELS && _levels[i] != level)
		i++;
	return (i < NUMBER_OF_LEVELS ? (Level)(i) : UNKNOWN);
}

void Harl::complain(std::string level)
{
	switch (getLevel(level))
	{
	case 0:
		std::cout << "[ " << _levels[0] << " ]" << std::endl;
		(this->*arr[0])();
		std::cout << std::endl;

	case 1:
		std::cout << "[ " << _levels[1] << " ]" << std::endl;
		(this->*arr[1])();
		std::cout << std::endl;

	case 2:
		std::cout << "[ " << _levels[2] << " ]" << std::endl;
		(this->*arr[2])();
		std::cout << std::endl;

	case 3:
		std::cout << "[ " << _levels[3] << " ]" << std::endl;
		(this->*arr[3])();
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
