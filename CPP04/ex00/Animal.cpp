/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:25 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 12:15:05 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	_type = "Unknown";
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of Animal\e[0m" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}

// Operators
Animal &Animal::operator=(const Animal &assign)
{
	_type = assign.getType();
	return *this;
}

// Getters / Setters
std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	if (_type == "Cat")
		std::cout << "Meow!" << std::endl;
	else if (_type == "Dog")
		std::cout << "Woof!" << std::endl;
	else
		std::cout << "Sound of an animal..." << std::endl;
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Animal &object)
{
	stream << "Animal of type " << object.getType() << "" << std::endl;
	return stream;
}
