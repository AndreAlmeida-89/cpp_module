/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:45:17 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/09 12:11:39 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure()
{
	std::cout << "\e[0;33mDefault Constructor called of Cure\e[0m" << std::endl;
}

Cure::Cure(const Cure &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Cure\e[0m" << std::endl;
}


// Destructor
Cure::~Cure()
{
	std::cout << "\e[0;31mDestructor called of Cure\e[0m" << std::endl;
}


// Operators
Cure & Cure::operator=(const Cure &assign)
{
	(void) assign;
	return *this;
}

AMateria *Cure::clone() const
{
	return nullptr;
}

void Cure::use(ICharacter &target)
{
	(void)target;
}
