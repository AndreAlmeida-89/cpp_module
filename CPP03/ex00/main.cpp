/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/01 01:19:38 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	// Test Constructors
	ClapTrap clapTrap1;
	ClapTrap clapTrap2("ClapTrap2");
	ClapTrap clapTrap3(clapTrap2);

	// Test operator=
	clapTrap1 = clapTrap2;

	// Test member functions
	clapTrap1.attack("ClapTrap1");
	clapTrap1.takeDamage(10);
	clapTrap1.beRepaired(10);

	// Test getters
	std::cout << "ClapTrap1 name: " << clapTrap1.getName() << std::endl;
	std::cout << "ClapTrap1 hit points: " << clapTrap1.getHitPoints() << std::endl;
	std::cout << "ClapTrap1 energy points: " << clapTrap1.getEnergyPoints() << std::endl;
	std::cout << "ClapTrap1 attack damage: " << clapTrap1.getAttackDamage() << std::endl;

	// Test << operator
	std::cout << clapTrap1 << std::endl;

	return (0);
}