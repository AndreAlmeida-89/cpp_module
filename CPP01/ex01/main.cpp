/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:31:36 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/09 21:58:54 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	const int nbOfZombies = 10;
	Zombie *zombies;

	zombies = zombieHorde(nbOfZombies, "Zé");
	for (int i = 0; i < nbOfZombies; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}