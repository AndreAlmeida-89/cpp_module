/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:25 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 23:35:52 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal()
{
	_type = "Unknown";
	std::cout << "\e[0;33mDefault Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	std::cout << "\e[0;33mFields Constructor called of Animal\e[0m" << std::endl;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}

// Operators
AAnimal &AAnimal::operator=(const AAnimal &assign)
{
	_type = assign.getType();
	return *this;
}

// Getters / Setters
std::string AAnimal::getType() const
{
	return _type;
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AAnimal &object)
{
	stream << "Animal of type " << object.getType() << "" << std::endl;
	return stream;
}
