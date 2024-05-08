/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:49:28 by andde-so          #+#    #+#             */
/*   Updated: 2024/01/05 23:10:15 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{

	FragTrap *fragTrap1  = new FragTrap("joao");
	FragTrap fragtrap2 = *fragTrap1;
	// Test FragTrap member functions
	// std::cout << *fragTrap1 << std::endl;
	// fragTrap1->attack("FragTrap1");
	// fragTrap1->takeDamage(10);
	// fragTrap1->beRepaired(5);
	// fragTrap1->highFivesGuys();
	// std::cout << *fragTrap1 << std::endl;

	delete fragTrap1;

	return (0);
}