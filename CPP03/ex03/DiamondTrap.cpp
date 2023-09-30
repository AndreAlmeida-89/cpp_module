#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap()
{
	_name = "";
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	_name = copy.getName();
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	std::cout << "\e[0;33mFields Constructor called of DiamondTrap\e[0m" << std::endl;
}

/*
Its attributes and member functions will be picked from either one of its parent classes:
•Name, which is passed as parameter to a constructor
•ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
•Hit points (FragTrap)
•Energy points (ScavTrap)
•Attack damage (FragTrap)
*/
DiamondTrap::DiamondTrap(std::string name, int hitPoints, int energyPoints, int atackDamage)
	: ClapTrap(name + "_clap_name")
{
	this->_name = name;
	FragTrap::setHitPoints(hitPoints);
	ScavTrap::setEnergyPoints(energyPoints);
	FragTrap::setAtackDamage(atackDamage);
	std::cout << "\e[0;33mFields Constructor called of DiamondTrap\e[0m" << std::endl;
}
// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}

// Operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &assign)
{
	_name = assign.getName();
	return *this;
}

// Getters / Setters
std::string DiamondTrap::getName() const
{
	return _name;
}

void DiamondTrap::setName(std::string name)
{
	this->_name = name;
}

// Member Functions
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap(" << _name << ")" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}