/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:29:56 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/30 23:16:41 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	// Constructors
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);

	// Destructor
	~FragTrap();

	// Operators
	FragTrap &operator=(const FragTrap &assign);

	// Getters
	int getHitPoints() const;

	// Member Functions
	void highFivesGuys();
};

#endif