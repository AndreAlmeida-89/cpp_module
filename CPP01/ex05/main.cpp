/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:19:01 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/12 01:01:26 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl(/* args */);
	~Harl();
	void complain(std::string level);
};

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*arr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	size_t res = levels->find_first_of(level);
	std::cout << "res: " << res << std::endl;
	std::cout << arr  << std::endl;
	// switch (level)
	// {
	// case /* constant-expression */:
	// 	/* code */
	// 	break;

	// default:
	// 	break;
	// }
}

void Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error" << std::endl;
}

int main(void)
{
	Harl h = Harl();
	h.complain("DEBUG");
	return (0);
}