/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/01 01:29:30 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	// Test DiamondTrap constructor
	DiamondTrap diamondTrap1("DiamondTrap1");

	// Test member functions
	std::cout << diamondTrap1 << std::endl;
	diamondTrap1.whoAmI();
	diamondTrap1.attack("DiamondTrap1");
	diamondTrap1.takeDamage(10);
	diamondTrap1.beRepaired(10);
	std::cout << diamondTrap1 << std::endl;

	return (0);
}