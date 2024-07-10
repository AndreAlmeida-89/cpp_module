/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:23:17 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/10 14:03:53 by andde-so         ###   ########.fr       */
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
	_type = copy.getType();
	_brain = new Brain(copy.getBrain());
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
	_type = assign.getType();
	_brain = new Brain(assign.getBrain());
	return *this;
}

// Member functions
void Cat::makeSound() const
{
	std::cout << "\e[0;32mMeow Meow!\e[0m" << std::endl;
}

const Brain &Cat::getBrain() const
{
	return (*_brain);
}
