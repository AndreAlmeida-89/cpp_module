/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:56 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/30 21:59:53 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
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
};

#endif