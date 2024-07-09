/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:58:15 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/09 12:05:59 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	std::cout << "\e[0;33mDefault Constructor called of MateriaSource\e[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of MateriaSource\e[0m" << std::endl;
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "\e[0;31mDestructor called of MateriaSource\e[0m" << std::endl;
}

// Operators
MateriaSource &MateriaSource::operator=(const MateriaSource &assign)
{
	(void)assign;
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	(void)m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	(void)type;
	return nullptr;
}
