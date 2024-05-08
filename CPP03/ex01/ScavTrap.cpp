/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:39 by andde-so          #+#    #+#             */
/*   Updated: 2024/01/05 23:47:56 by andde-so         ###   ########.fr       */
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
	setName(name);
	ClapTrap::setHitPoints(100);
	setEnergyPoints(50);
	setattackDamage(20);
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

int ScavTrap::getHitPoints() const
{
	std::cout << "hello!" << std::endl;
	return ClapTrap::getHitPoints();
}

void ScavTrap::setHitPoints(int hitPoints)
{
	if (hitPoints > 80)
		ClapTrap::setHitPoints(500);
	else
		ClapTrap::setHitPoints(hitPoints);
}