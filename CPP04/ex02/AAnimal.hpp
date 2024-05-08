/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 23:35:36 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
public:
	// Constructors
	AAnimal();
	AAnimal(const AAnimal &copy);
	AAnimal(const std::string &type);

	// Destructor
	virtual ~AAnimal();

	// Operators
	AAnimal &operator=(const AAnimal &assign);

	// Member functions
	virtual void makeSound() const = 0;
	std::string getType() const;

protected:
	std::string _type;

};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AAnimal &object);

#endif