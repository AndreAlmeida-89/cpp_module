/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:23:17 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 16:28:27 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	_type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

// Operators
Cat &Cat::operator=(const Cat &assign)
{
	Animal::operator=(assign);
	return *this;
}

// Member functions
void Cat::makeSound() const
{
	std::cout << "\e[0;32mMeow Meow!\e[0m" << std::endl;
}