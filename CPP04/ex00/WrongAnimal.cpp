/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:25 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 11:59:14 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	_type = "WrongUnknown";
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of WrongAnimal\e[0m" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}

// Operators
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	_type = assign.getType();
	return *this;
}

// Getters / Setters
std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	if (_type == "Cat")
		std::cout << "Meow!" << std::endl;
	else if (_type == "Dog")
		std::cout << "Woof!" << std::endl;
	else
		std::cout << "WrongAnimal sound" << std::endl;
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const WrongAnimal &object)
{
	stream << "Animal of type " << object.getType() << "" << std::endl;
	return stream;
}
