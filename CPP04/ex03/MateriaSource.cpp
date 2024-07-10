/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:58:15 by andde-so          #+#    #+#             */
/*   Updated: 2024/07/09 21:17:51 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource() : _inventoryCount(0)
{
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (size_t i = 0; i < _inventoryCapacity; i++)
	{
		_inventory[i] = copy.getMateria(i);
		if (_inventory[i] != NULL)
			_inventoryCount++;
	}
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < _inventoryCount; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

// Operators
MateriaSource &MateriaSource::operator=(const MateriaSource &assign)
{
	for (size_t i = 0; i < _inventoryCapacity; i++)
	{
		_inventory[i] = assign.getMateria(i);
		if (_inventory[i] != NULL)
			_inventoryCount++;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_inventoryCount < _inventoryCapacity)
	{
		_inventory[_inventoryCount] = m;
		_inventoryCount++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < _inventoryCount; i++)
	{
		if (getMateria(i)->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}

AMateria *MateriaSource::getMateria(size_t index) const
{
	if (index < _inventoryCount)
		return (_inventory[index]);
	return (NULL);
}
