#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int atackDamage)
	: ClapTrap(name, hitPoints, energyPoints, atackDamage)
{
	std::cout << "\e[0;33mFields Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	(void)copy;
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

// Member Functions
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " is asking for high fives" << std::endl;
}
