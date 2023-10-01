#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	_name = copy._name;
	ClapTrap::_name = copy._name + "_clap_name";
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_energyPoints = 50;
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
	this->ClapTrap::operator=(assign);
	std::cout << "\e[0;33mAssignation Operator called of DiamondTrap\e[0m" << std::endl;
	return *this;
}

// Member Functions
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap(" << _name << ")"
			  << " ClapTrap(" << ClapTrap::_name << ")" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}