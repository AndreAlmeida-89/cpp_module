#include "Character.hpp"

// Constructors
Character::Character() : _count(0)
{
	memset(_inventory, 0, sizeof(_inventory));
	_count++; //TODO: remove
	std::cout << "\e[0;33mDefault Constructor called of Character\e[0m" << std::endl;
}

Character::Character(const Character &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Character\e[0m" << std::endl;
}

Character::Character(std::string name) : _name(name), _count(0)
{
	memset(_inventory, 0, sizeof(_inventory));
}

// Destructor
Character::~Character()
{
	std::cout << "\e[0;31mDestructor called of Character\e[0m" << std::endl;
}


// Operators
Character & Character::operator=(const Character &assign)
{
	(void) assign;
	return *this;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	(void)m;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter &target)
{
	(void)idx;
	(void)target;
}
