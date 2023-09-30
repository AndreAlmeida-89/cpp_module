/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/30 14:22:44 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
	// Test FragTrap constructors
	FragTrap fragTrap1;
	FragTrap fragTrap2("FragTrap2");
	FragTrap fragTrap3(fragTrap2);

	// Test FragTrap operator=
	fragTrap1 = fragTrap2;

	// Test FragTrap member functions
	fragTrap1.attack("FragTrap1");
	fragTrap1.takeDamage(10);
	fragTrap1.beRepaired(10);
	fragTrap1.highFivesGuys();

	return (0);
}