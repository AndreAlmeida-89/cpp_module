/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/30 20:48:17 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// Test ScavTrap constructors
	ScavTrap scavTrap1;
	ScavTrap scavTrap2("ScavTrap2");
	ScavTrap scavTrap3(scavTrap2);

	// Test ScavTrap operator=
	scavTrap1 = scavTrap2;

	// Test << operator
	std::cout << scavTrap1 << std::endl;

	// Test ScavTrap member functions
	scavTrap1.attack("ScavTrap1");
	scavTrap1.takeDamage(10);
	scavTrap1.beRepaired(10);
	scavTrap1.guardGate();
	std::cout << scavTrap1 << std::endl;

	return (0);
}