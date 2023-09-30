/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:39 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/25 21:30:58 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
	_isInGateKeeperMode = false;
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	_isInGateKeeperMode = copy.getIsInGateKeeperMode();
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name, int hitPoints, int energyPoints, int atackDamage)
	: ClapTrap(name, hitPoints, energyPoints, atackDamage)
{
	_isInGateKeeperMode = false;
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

// Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	_isInGateKeeperMode = assign.getIsInGateKeeperMode();
	return *this;
}

// Getters / Setters
bool ScavTrap::getIsInGateKeeperMode() const
{
	return _isInGateKeeperMode;
}

// Member Functions
void ScavTrap::guardGate()
{
	_isInGateKeeperMode = !_isInGateKeeperMode;
	std::cout << "ScavTrap " << getName() << " is now " << (_isInGateKeeperMode ? "in" : "out") << " of Gate Keeper Mode" << std::endl;
}

// Super class member functions
void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAtackDamage() << " points of damage!" << std::endl;
}
