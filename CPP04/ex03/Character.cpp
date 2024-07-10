#include "Character.hpp"

// Constructors
Character::Character() : _inventoryCount(0),
						 _unequipedInventoryCount(0)
{
}

Character::Character(const Character &copy) : _name(copy.getName())
{
	for (size_t i = 0; i < _unequipedInventoryCapacity; i++)
	{
		_unequipedInventory[i] = copy.getUnusedMateria(i);
		if (_unequipedInventory[i] != NULL)
			_unequipedInventoryCount++;
	}
	for (size_t i = 0; i < _inventoryCapacity; i++)
	{
		_inventory[i] = copy.getMateria(i);
		if (_inventory[i] != NULL)
			_inventoryCount++;
	}
}

Character::Character(std::string name) : _name(name),
										 _inventoryCount(0),
										 _unequipedInventoryCount(0)
{
}

// Destructor
Character::~Character()
{
	for (size_t i = 0; i < _inventoryCapacity; i++)
	{
		if (_inventory[i] == NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (size_t i = 0; i < _unequipedInventoryCount; i++)
	{
		if (_unequipedInventory[i] == NULL)
		{
			delete _unequipedInventory[i];
			_unequipedInventory[i] = NULL;
		}
	}
}

// Operators
Character &Character::operator=(const Character &assign)
{
	_name = assign.getName();
	for (size_t i = 0; i < _unequipedInventoryCapacity; i++)
	{
		_unequipedInventory[i] = assign.getUnusedMateria(i);
		if (_unequipedInventory[i] != NULL)
			_unequipedInventoryCount++;
	}
	for (size_t i = 0; i < _inventoryCapacity; i++)
	{
		_inventory[i] = assign.getMateria(i);
		if (_inventory[i] != NULL)
			_inventoryCount++;
	}
	return *this;
}

std::string const &Character::getName() const
{
	return (_name);
}

AMateria *Character::getMateria(size_t idx) const
{
	if ((size_t)idx < _inventoryCount)
		return _inventory[idx];
	return NULL;
}

AMateria *Character::getUnusedMateria(size_t idx) const
{
	if (_unequipedInventoryCapacity < (size_t)idx)
		return _unequipedInventory[idx];
	return NULL;
}

void Character::equip(AMateria *materia)
{
	for (size_t i = 0; i < _inventoryCapacity; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = materia;
			_inventoryCount++;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	AMateria *unequipedMateria = getMateria(idx);
	if (unequipedMateria != NULL)
	{
		_inventory[idx] = NULL;
		_inventoryCount--;
		if (_unequipedInventoryCount < _unequipedInventoryCapacity)
		{
			_unequipedInventory[_unequipedInventoryCount] = unequipedMateria;
			_unequipedInventoryCount++;
		}
		else
		{
			std::cerr << "\e[0;31mDeleting " << unequipedMateria->getType() << "\e[0m" << std::endl;
			delete unequipedMateria;
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	AMateria *materia = getMateria(idx);
	if (materia != NULL)
		materia->use(target);
}