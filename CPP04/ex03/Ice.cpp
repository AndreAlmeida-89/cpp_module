/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:45:15 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/09 12:04:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice")
{
	std::cout << "\e[0;33mDefault Constructor called of Ice\e[0m" << std::endl;
}

Ice::Ice(const Ice &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Ice\e[0m" << std::endl;
}


// Destructor
Ice::~Ice()
{
	std::cout << "\e[0;31mDestructor called of Ice\e[0m" << std::endl;
}


// Operators
Ice & Ice::operator=(const Ice &assign)
{
	(void) assign;
	return *this;
}

AMateria *Ice::clone() const
{
	return nullptr;
}

void Ice::use(ICharacter &target)
{
	(void)target;
}
