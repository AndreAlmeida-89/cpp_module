/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:37:18 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/09 14:50:46 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria &copy) : _type(copy.getType())
{
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

// Destructor
AMateria::~AMateria()
{
}

// Operators
AMateria &AMateria::operator=(const AMateria &assign)
{
	_type = assign.getType();
	return *this;
}

// Getters / Setters
std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
