/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:32 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/01 01:19:37 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
									   _hitPoints(10),
									   _energyPoints(10),
									   _attackDamage(0)
{
	std::cout << "\e[0;33mFields Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy.getName()),
										   _hitPoints(copy.getHitPoints()),
										   _energyPoints(copy.getEnergyPoints()),
										   _attackDamage(copy.getAttackDamage())
{
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}

// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	_name = assign.getName();
	_hitPoints = assign.getHitPoints();
	_energyPoints = assign.getEnergyPoints();
	_attackDamage = assign.getAttackDamage();
	std::cout << "\e[0;33mAssignation Operator called of ClapTrap\e[0m" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap)
{
	os << "ClapTrap(" << clapTrap.getName() << ", " << clapTrap.getHitPoints() << ", " << clapTrap.getEnergyPoints() << ", " << clapTrap.getAttackDamage() << ")";
	return os;
}

// Getters / Setters
std::string ClapTrap::getName() const
{
	return _name;
}
void ClapTrap::setName(std::string name)
{
	_name = name;
}

int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::setattackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

// Member Functions
void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (_hitPoints - amount < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " is repaired " << amount << " points of damage!" << std::endl;
	_hitPoints += amount;
}