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
	DiamondTrap(std::string name,
				int hitPoints,
				int energyPoints,
				int atackDamage);

	// Destructor
	~DiamondTrap();

	// Operators
	DiamondTrap &operator=(const DiamondTrap &assign);

	// Getters / Setters
	std::string getName() const;
	void setName(std::string name);

	// Member functions
	void attack(std::string const &target);
	void whoAmI();

private:
	std::string _name;
};

#endif