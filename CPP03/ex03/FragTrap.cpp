#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\e[0;33mFields Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

// Operators
FragTrap &FragTrap::operator=(const FragTrap &assign)
{
	this->ClapTrap::operator=(assign);
	return *this;
}

// Getters
int FragTrap::getHitPoints() const
{
	return _hitPoints;
}

// Member Functions
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " is asking for high fives" << std::endl;
}
