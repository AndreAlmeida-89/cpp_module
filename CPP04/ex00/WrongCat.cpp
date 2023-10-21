/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:23:17 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 16:31:14 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}

// Operators
WrongCat &WrongCat::operator=(const WrongCat &assign)
{
	WrongAnimal::operator=(assign);
	return *this;
}

// Member functions
void WrongCat::makeSound() const
{
	std::cout << "\e[0;32mMeow Meow!\e[0m" << std::endl;
}