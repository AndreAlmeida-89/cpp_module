#include "Character.hpp"

// Constructors
Character::Character()
{
	std::cout << "\e[0;33mDefault Constructor called of Character\e[0m" << std::endl;
}

Character::Character(const Character &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Character\e[0m" << std::endl;
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

