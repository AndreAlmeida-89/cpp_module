#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	// Constructors
	DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);

	// Destructor
	~DiamondTrap();

	// Operators
	DiamondTrap &operator=(const DiamondTrap &assign);

	// Member functions
	void attack(std::string const &target);
	void whoAmI();

private:
	std::string _name;
};

#endif