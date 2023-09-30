/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:56 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/30 17:24:10 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	// Constructors
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name,
			 int hitPoints = 100,
			 int energyPoints = 100,
			 int atackDamage = 30);

	// Destructor
	~FragTrap();

	// Operators
	FragTrap &operator=(const FragTrap &assign);

	// Member Functions
	void highFivesGuys();
};

#endif