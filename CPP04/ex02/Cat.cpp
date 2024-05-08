/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:23:17 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 23:28:10 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
	delete _brain;
}

// Operators
Cat &Cat::operator=(const Cat &assign)
{
	AAnimal::operator=(assign);
	return *this;
}

// Methods
void Cat::makeSound() const
{
	std::cout << "\e[0;32mCat says: \"Meow Meow\"\e[0m" << std::endl;
}
