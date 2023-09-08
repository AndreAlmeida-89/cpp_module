/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:31:36 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/04 12:06:16 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie z1 = Zombie("z1");
	z1.announce();

	Zombie *z2 = newZombie("z2");
	z2->announce();
	delete z2;

	randomChump("z3");

	return (0);
}