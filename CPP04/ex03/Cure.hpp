/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:45:21 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 22:45:22 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	// Constructors
	Cure();
	Cure(const Cure &copy);

	// Destructor
	~Cure();

	// Operators
	Cure &operator=(const Cure &assign);

	// Member functions
	AMateria *clone() const;
	void use(ICharacter &target);

private:
};

#endif