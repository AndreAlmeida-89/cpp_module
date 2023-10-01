/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:39 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/01 01:19:38 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

// Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	this->ClapTrap::operator=(assign);
	std::cout << "\e[0;33mAssignation Operator called of ScavTrap\e[0m" << std::endl;
	return *this;
}

// Member Functions
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " has entered Gate Keeper Mode" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}
