/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 11:45:23 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	// Constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal(std::string type);

	// Destructor
	~WrongAnimal();

	// Operators
	WrongAnimal &operator=(const WrongAnimal &assign);

	// Getters / Setters
	std::string getType() const;

	// Member functions
	void makeSound() const;

protected:
	std::string _type;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const WrongAnimal &object);

#endif