/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:20:43 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/09 18:41:41 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
	_type = copy.getType();
	_brain = new Brain(copy.getBrain());
}


// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
	delete _brain;
}

// Operators
Dog &Dog::operator=(const Dog &assign)
{
	std::cout << "\e[0;33mCopy Operator called of Dog\e[0m" << std::endl;
	_type = assign.getType();
	_brain = new Brain(assign.getBrain());
	return *this;
}

// Methods
void Dog::makeSound() const
{
	std::cout << "\e[0;32mDog says: \"Woof Woof\"\e[0m" << std::endl;
}


const Brain &Dog::getBrain() const
{
	return (*_brain);
}
