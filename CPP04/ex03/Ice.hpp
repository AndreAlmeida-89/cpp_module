/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:45:11 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 22:45:52 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	// Constructors
	Ice();
	Ice(const Ice &copy);

	// Destructor
	~Ice();

	// Operators
	Ice &operator=(const Ice &assign);

	// Member functions
	AMateria *clone() const;
	void use(ICharacter &target);

private:
};

#endif