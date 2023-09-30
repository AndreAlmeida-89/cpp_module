/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/30 19:15:06 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main()
{
	// Test DiamondTrap constructors
	DiamondTrap diamondTrap1;
	DiamondTrap diamondTrap2("DiamondTrap2");
	DiamondTrap diamondTrap3(diamondTrap2);

	// Test DiamondTrap operator=
	diamondTrap1 = diamondTrap2;

	// Test DiamondTrap member functions
	diamondTrap1.attack("DiamondTrap1");
	diamondTrap1.takeDamage(10);
	diamondTrap1.beRepaired(10);
	diamondTrap1.highFivesGuys();
	diamondTrap1.guardGate();
	diamondTrap1.whoAmI();

	//test DiamondTrap getters
	std::cout << "DiamondTrap1 name: " << diamondTrap1.getName() << std::endl;
	std::cout << "DiamondTrap1 hit points: " << diamondTrap1.getHitPoints() << std::endl;
	std::cout << "DiamondTrap1 energy points: " << diamondTrap1.getEnergyPoints() << std::endl;
	std::cout << "DiamondTrap1 atack damage: " << diamondTrap1.getAtackDamage() << std::endl;
	
	//test DiamondTrap << operator
	std::cout << diamondTrap1 << std::endl;
	return (0);
}