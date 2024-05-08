/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:56 by andde-so          #+#    #+#             */
/*   Updated: 2024/01/05 23:35:44 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// Constructors
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap();

	// Operators
	ScavTrap &operator=(const ScavTrap &assign);

	// Member Functions
	void attack(std::string const &target);
	void guardGate();


	int getHitPoints() const;
	void setHitPoints(int hitPoints);
};

#endif