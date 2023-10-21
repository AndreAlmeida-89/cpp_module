/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 16:25:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	// Constructors
	Animal();
	Animal(const Animal &copy);
	Animal(std::string type);

	// Destructor
	~Animal();

	// Operators
	Animal &operator=(const Animal &assign);

	// Getters / Setters
	std::string getType() const;

	// Member functions
	void makeSound() const;

protected:
	std::string _type;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Animal &object);

#endif