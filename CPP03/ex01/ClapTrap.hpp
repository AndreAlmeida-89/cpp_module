/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:35 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/01 01:19:38 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
public:
	// Constructors
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string name);

	// Destructor
	~ClapTrap();

	// Operators
	ClapTrap &operator=(const ClapTrap &assign);

	// Getters / Setters
	std::string getName() const;
	void setName(std::string name);
	int getHitPoints() const;
	void setHitPoints(int hitPoints);
	int getEnergyPoints() const;
	void setEnergyPoints(int energyPoints);
	int getAttackDamage() const;
	void setattackDamage(int attackDamage);

	// Member Functions
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

// << Operator overload
std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap);

#endif