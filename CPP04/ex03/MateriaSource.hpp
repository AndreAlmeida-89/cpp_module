/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:58:11 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 23:00:31 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	// Constructors
	MateriaSource();
	MateriaSource(const MateriaSource &copy);

	// Destructor
	~MateriaSource();

	// Operators
	MateriaSource &operator=(const MateriaSource &assign);

	// Member functions
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

private:
};

#endif