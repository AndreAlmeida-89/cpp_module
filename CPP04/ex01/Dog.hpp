/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:20:53 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 15:49:08 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	// Constructors
	Dog();
	Dog(const Dog &copy);
	Dog(const std::string &type);

	// Destructor
	~Dog();

	// Operators
	Dog &operator=(const Dog &assign);

private:
	Brain *_brain;
};

#endif