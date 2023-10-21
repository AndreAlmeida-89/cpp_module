/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:20:53 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 16:27:42 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	// Constructors
	Dog();
	Dog(const Dog &copy);

	// Destructor
	~Dog();

	// Operators
	Dog &operator=(const Dog &assign);

	// Member functions
	void makeSound() const;

private:
};

#endif