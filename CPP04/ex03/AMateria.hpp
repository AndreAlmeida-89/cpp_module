/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:37:15 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 22:38:27 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	// Constructors
	AMateria();
	AMateria(const AMateria &copy);
	AMateria(std::string const &_type);

	// Destructor
	~AMateria();

	// Operators
	AMateria &operator=(const AMateria &assign);

	// Getters / Setters
	std::string const &getType() const;

	// Member functions
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};
#endif